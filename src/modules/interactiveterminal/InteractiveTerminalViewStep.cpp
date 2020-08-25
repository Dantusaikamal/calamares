/* === This file is part of Calamares - <https://calamares.io> ===
 *
 *   SPDX-FileCopyrightText: 2014-2015 Teo Mrnjavac <teo@kde.org>
 *   SPDX-License-Identifier: GPL-3.0-or-later
 *
 *   Calamares is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   Calamares is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with Calamares. If not, see <http://www.gnu.org/licenses/>.
 */

#include "InteractiveTerminalViewStep.h"

#include "InteractiveTerminalPage.h"

#include "utils/Logger.h"

#include <QVariant>

CALAMARES_PLUGIN_FACTORY_DEFINITION( InteractiveTerminalViewStepFactory,
                                     registerPlugin< InteractiveTerminalViewStep >(); )

InteractiveTerminalViewStep::InteractiveTerminalViewStep( QObject* parent )
    : Calamares::ViewStep( parent )
    , m_widget( new InteractiveTerminalPage() )
{
    emit nextStatusChanged( true );
}


InteractiveTerminalViewStep::~InteractiveTerminalViewStep()
{
    if ( m_widget && m_widget->parent() == nullptr )
    {
        m_widget->deleteLater();
    }
}


QString
InteractiveTerminalViewStep::prettyName() const
{
    return tr( "Script" );
}


QWidget*
InteractiveTerminalViewStep::widget()
{
    return m_widget;
}


bool
InteractiveTerminalViewStep::isNextEnabled() const
{
    return true;
}


bool
InteractiveTerminalViewStep::isBackEnabled() const
{
    return true;
}


bool
InteractiveTerminalViewStep::isAtBeginning() const
{
    return true;
}


bool
InteractiveTerminalViewStep::isAtEnd() const
{
    return true;
}


QList< Calamares::job_ptr >
InteractiveTerminalViewStep::jobs() const
{
    cDebug() << "InteractiveTerminal" << prettyName() << "asked for jobs(), this is probably wrong.";
    return QList< Calamares::job_ptr >();
}


void
InteractiveTerminalViewStep::onActivate()
{
    cDebug() << "InteractiveTerminal" << prettyName() << "activated.";
    m_widget->onActivate();
}


void
InteractiveTerminalViewStep::setConfigurationMap( const QVariantMap& configurationMap )
{
    if ( configurationMap.contains( "command" ) && configurationMap.value( "command" ).type() == QVariant::String )
    {
        m_widget->setCommand( configurationMap.value( "command" ).toString() );
    }
}
