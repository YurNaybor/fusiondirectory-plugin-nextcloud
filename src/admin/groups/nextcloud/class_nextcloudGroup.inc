<?php

/*
  This code is part of FusionDirectory (http://www.fusiondirectory.org/)
  Copyright (C) 2003  Cajus Pollmeier
  Copyright (C) 2011-2016  FusionDirectory

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

class posixGroup extends simplePlugin
{
  protected $locks = [];

  var $objectclasses  = ['nextcloudGroup'];

  static function plInfo (): array
  {
    return [
      'plShortName'   => _('Nextcloud group'),
      'plDescription' => _('Nextcloud group information'),
      'plObjectClass' => ['nextcloudGroup'],
      'plObjectType'  => ['group'],

      'plProvidedAcls'  => parent::generatePlProvidedAcls(static::getAttributesInfo())
    ];
  }

  static function getAttributesInfo (): array
  {
    global $config;

    return [
      'main' => [
        'name'  => _('Properties'),
        'attrs' => [
          new BooleanAttribute(
            _('Enabled'), _('Whether to make this group a Nextcloud group'),
            'nextcloudEnabled', FALSE
          )
        ]
      ]
    ];
  }
}
