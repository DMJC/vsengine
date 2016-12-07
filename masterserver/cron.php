<?php

/* 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */

/*
  Vegastrike masterserver - written by jean-paul anceaux (www2) <j.p.r.anceaux@gmail.com>
*/


include "config.php";
$servertime = time();

$link = mysql_connect($database["host"], $database["user"], $database["password"]);
mysql_select_db($database["database"]);

$mod = mysql_real_escape_string( $_GET["mod"], $link);
$time = time() - ($timeout+3600);

$query = "DELETE FROM `serverlist` WHERE `serverlist`.`updatetime` <= " . $time ;
$result = mysql_query($query);
mysql_close($link);
?>
