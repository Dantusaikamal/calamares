/* === This file is part of Calamares - <https://calamares.io> ===
 *
 *   SPDX-FileCopyrightText: 2020 Adriaan de Groot <groot@kde.org>
 *   SPDX-License-Identifier: GPL-3.0-or-later
 *
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
 *
 */

/* @file Turn off warnings on MOC-generated code
 *
 * This header file exists **only** to reduce warnings during compilation.
 * Code generated by Qt's MOC, in combination with Clang (version 6 or later,
 * I'm fairly sure) and the plenty-of-warnings settings that Calamares uses,
 * triggers tons of warnings. Since those warnings are not something we
 * can do anything about, turn them off by `#include`ing this header
 * before a MOC file.
 *
 * Note that not many files in Calamares use MOC directly: mostly CMake's
 * automoc does all the work for us.
 */
#ifdef __clang__
#pragma clang diagnostic ignored "-Wextra-semi-stmt"
#pragma clang diagnostic ignored "-Wredundant-parens"
#endif
