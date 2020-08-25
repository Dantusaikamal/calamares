/* === This file is part of Calamares - <https://calamares.io> ===
 *
 *   SPDX-FileCopyrightText: 2017-2018 Adriaan de Groot <groot@kde.org>
 *   SPDX-License-Identifier: GPL-3.0-or-later
 *
 *   Calamares is Free Software: see the License-Identifier above.
 *
 */

#include "ThemeWidget.h"

#include "ThemeInfo.h"

#include "Branding.h"
#include "utils/CalamaresUtilsGui.h"
#include "utils/Logger.h"

#include <QDir>
#include <QFileInfo>
#include <QHBoxLayout>
#include <QLabel>
#include <QRadioButton>
#include <QString>

/**
 * Massage the given @p path to the most-likely
 * path that actually contains a screenshot. For
 * empty image paths, returns the QRC path for an
 * empty screenshot. Returns blank if the path
 * doesn't exist anywhere in the search paths.
 */
static QString
_munge_imagepath( const QString& path )
{
    if ( path.isEmpty() )
    {
        return ":/view-preview.png";
    }

    if ( path.startsWith( '/' ) )
    {
        return path;
    }

    if ( QFileInfo::exists( path ) )
    {
        return path;
    }

    QFileInfo fi( QDir( Calamares::Branding::instance()->componentDirectory() ), path );
    if ( fi.exists() )
    {
        return fi.absoluteFilePath();
    }

    return QString();
}

ThemeWidget::ThemeWidget( const ThemeInfo& info, QWidget* parent )
    : QWidget( parent )
    , m_id( info.id )
    , m_check( new QRadioButton( info.name.isEmpty() ? info.id : info.name, parent ) )
    , m_description( new QLabel( info.description, parent ) )
{
    const QSize image_size { qMax( 12 * CalamaresUtils::defaultFontHeight(), 120 ),
                             qMax( 8 * CalamaresUtils::defaultFontHeight(), 80 ) };

    QHBoxLayout* layout = new QHBoxLayout( this );
    this->setLayout( layout );

    layout->addWidget( m_check, 1 );

    QPixmap image( _munge_imagepath( info.imagePath ) );
    if ( image.isNull() )
    {
        // Not found or not specified, so convert the name into some (horrible, likely)
        // color instead.
        image = QPixmap( image_size );
        auto hash_color = qHash( info.imagePath.isEmpty() ? info.id : info.imagePath );
        cDebug() << "Theme image" << info.imagePath << "not found, hash" << hash_color;
        image.fill( QColor( QRgb( hash_color ) ) );
    }

    image = image.scaled( image_size, Qt::IgnoreAspectRatio, Qt::SmoothTransformation );

    QLabel* image_label = new QLabel( this );
    image_label->setPixmap( image );
    image_label->setMinimumSize( image_size );
    image_label->setMaximumSize( image_size );
    image_label->setSizePolicy( QSizePolicy::Fixed, QSizePolicy::Fixed );
    layout->addWidget( image_label, 1 );
    layout->addWidget( m_description, 3 );

    connect( m_check, &QRadioButton::toggled, this, &ThemeWidget::clicked );
}

void
ThemeWidget::clicked( bool checked )
{
    if ( checked )
    {
        emit themeSelected( m_id );
    }
}

QAbstractButton*
ThemeWidget::button() const
{
    return m_check;
}

void
ThemeWidget::updateThemeName( const ThemeInfo& info )
{
    m_check->setText( info.name );
    m_description->setText( info.description );
}
