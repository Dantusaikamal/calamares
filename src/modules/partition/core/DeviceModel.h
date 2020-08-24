/* === This file is part of Calamares - <https://github.com/calamares> ===
 *
 *   SPDX-FileCopyrightText: 2014 Aurélien Gâteau <agateau@kde.org>
 *   SPDX-FileCopyrightText: 2017 2019, Adriaan de Groot <groot@kde.org>
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
#ifndef DEVICEMODEL_H
#define DEVICEMODEL_H

#include <QAbstractListModel>
#include <QList>
#include <QScopedPointer>

class Device;
class PartitionModel;

/**
 * A Qt model which exposes a list of Devices.
 */
class DeviceModel : public QAbstractListModel
{
    Q_OBJECT
public:
    DeviceModel( QObject* parent = nullptr );
    ~DeviceModel() override;

    using DeviceList = QList< Device* >;

    /**
     * Init the model with the list of devices. Does *not* take ownership of the
     * devices.
     */
    void init( const DeviceList& devices );

    int rowCount( const QModelIndex& parent = QModelIndex() ) const override;
    QVariant data( const QModelIndex& index, int role = Qt::DisplayRole ) const override;

    Device* deviceForIndex( const QModelIndex& index ) const;

    void swapDevice( Device* oldDevice, Device* newDevice );

    void addDevice( Device* device );

    void removeDevice( Device* device );

private:
    DeviceList m_devices;
};

#endif /* DEVICEMODEL_H */
