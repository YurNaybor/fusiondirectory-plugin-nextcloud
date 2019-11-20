<?php
/*
  This code is part of FusionDirectory (http://www.fusiondirectory.org/)

  Copyright (C) 2003  Cajus Pollmeier
  Copyright (C) 2011-2019  FusionDirectory

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA.
*/

/*!
  \brief   nextcloudAccount plugin
  \author  Benjamin Voigt <de_doener@web.de>
  \version 1.00
  \date    10.11.2019

  Implement a basic Nextcloud account management.
 */

class nextcloudAccount extends simplePlugin
{
  protected $displayHeader        = TRUE;

  var $objectclasses  = ['nextcloudAccount'];

  static function plInfo (): array
  {
    return [
      'plShortName'   => _('Nextcloud'),
      'plDescription' => _('Edit user\'s Nextcloud settings'),
      'plFilter'      => '(objectClass=nextcloudAccount)',
      'plIcon'        => 'geticon.php?context=applications&icon=nextcloud&size=48',
      'plSmallIcon'   => 'geticon.php?context=applications&icon=nextcloud&size=16',
      'plSelfModify'  => TRUE,
      'plObjectClass' => ['nextcloudAccount'],
      'plObjectType'  => ['user'],

      'plProvidedAcls'  => parent::generatePlProvidedAcls(static::getAttributesInfo())
    ];
  }

  // The main function : information about attributes
  static function getAttributesInfo (): array
  {
    global $config;
    return [
      'main' => [
        'name'  => _('Nextcloud'),
        'icon'  => 'geticon.php?context=applications&icon=nextcloud&size=16',
        'attrs' => [
          new BooleanAttribute(
            _('Nextcloud enabled'), _('Whether Nextcloud is enabled for this user'),
            'nextcloudEnabled', FALSE
          ),
          new IntAttribute(
            _('Nextcloud quota'), _('Quota (in GB) for this user in Nextcloud'),
            'nextcloudQuota', FALSE, FALSE, FALSE
          )
        ]
      ]
    ];
  }
}
