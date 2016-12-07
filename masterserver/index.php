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

//if (!isset($_GET['server_id']))
//{
	$query = "SELECT * FROM serverlist WHERE `updatetime` >=" . (time() - $timeout);
	$result = mysql_query($query);

	while ($outeput = mysql_fetch_array($result, MYSQL_ASSOC))
	{
      
	      $dateDiff = $servertime - $outeput['singuptime'];
      
	      $fullDays = floor($uptimeraw/(60*60*24));
	      $fullDays    = floor($dateDiff/(60*60*24));
	      $fullHours   = floor(($dateDiff-($fullDays*60*60*24))/(60*60));
	      $fullMinutes = floor(($dateDiff-($fullDays*60*60*24)-($fullHours*60*60))/60); 
	      $fullSecond = floor(($dateDiff-($fullDays*60*60*24)-($fullHours*60*60)-($fullMinutes*60)));
	      
	      $uptime = $fullDays . ' ' . $fullHours . ':' . $fullMinutes . ':' . $fullSecond;
	      if ($outeput["password"] == "0")
	      {
		      $password = "<img src=\"img/lock_open.png\" />";
	      }
	      elseif ($outeput["password"] == "1")
	      {
		      $password = "<img src=\"img/lock.png\" />";
	      }
	      $list .= "<tr>\n";
	      $list .= "<td>" . $outeput["name"] . "</td>\n";
	      $list .= "<td>" . $outeput["ipadress"] . ":" . $outeput["port"] . "</td>\n";
	      $list .= "<td>" . $outeput["mod"] . "</td>\n";
	      $list .= "<td>" . $outeput["currentplayers"] . "/" . $outeput["maxplayers"] . "</td>\n";
	      $list .= "<td>" . $password . "</td>\n";
	      $list .= "<td>" . $uptime . "</td>\n";
	      $list .= "</tr>\n";
	}
	
	$body = "<table style=\"text-align: left; width: 100%;\" border=\"1\" cellpadding=\"2\" cellspacing=\"2\">
	  <tbody>
	   <tr>
	     <td>server name</td>
	     <td>ip adress</td>
	     <td>mod</td>
	     <td>Players</td>
	     <td>password</td>
	     <td>uptime</td>
	   </tr>
	   ". $list ."
	 </tbody>
	</table>";
//}
mysql_close($link);
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.1//EN" "http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en">
<head>    <meta http-equiv="content-type" content="text/html; charset=utf-8" />
    <title>Vega Strike - Home</title>
    <link type="text/css" rel="stylesheet" href="layout/css/default.css" />
</head>
<body>
    <div id="tagline"></div>
    <div id="logo"></div>
    <div id="menu">
        <!-- Because these are float righted, the first listed here is last on the page -->
        <a href="http://vegastrike.sf.net">Vegastike site</a>
    </div>
    <div id="background"></div>
    
    <div id="downloads" class="column-right box">
        <h2>Get Vega Strike</h2>
        <p>Latest Stable: <a href="#">0.5</a><br />Latest Development: <a href="#">0.5.1</a></p>
        <p>Latest <a href="#">Subversion</a></p>
    </div>
    <div id="mods" class="column-right box">
        <h2>Mods</h2>
        <ul class="picture-list">
            <li>
                <a href="http://wcuniverse.sourceforge.net/"><img src="screenshots/privateer.jpg" alt="Privateer Remake Screenshot" /><br /><span class="caption">Privateer Remake</span></a>
            </li>
            <li>
                <a href="http://wcuniverse.sourceforge.net/vegatrek/"><img src="screenshots/vegatrek.jpg" alt="Vega Trek Screenshot" /><br /><span class="caption">Vega Trek</span></a>
            </li>
            <li>
                <a href="http://wcuniverse.sourceforge.net/forums/viewforum.php?f=31"><img src="screenshots/piarmada.jpg" alt="Pi Armada Screenshot" /><br /><span class="caption">Pi Armada</span></a>
            </li>
        </ul>
    </div>
    <div id="screenshots" class="column-right box">
        <h2>Screenshots</h2>
        <ul class="picture-list">
            <li>
                <a href="#"><img src="screenshots/lazer_rain_redux.jpg" alt="Lazer Rain Screenshot" /></a>
            </li>
            <li>
                <a href="#"><img src="screenshots/starting_system_fighterbase.jpg" alt="Fighterbase Screenshot" /></a>
            </li>
        </ul>
    </div>
    <div id="content" class="column-left box">
        <h1>Servers</h1>
        <? echo $body; ?>
    </div>
    <div id="affiliates" class="column-right">
        <a href="http://sourceforge.net/"><img src="buttons/sourceforge.net.gif" alt="Thanks to sourceforge.net for hosting the project." /></a>
        <a href="http://www.ogre3d.org/"><img src="buttons/ogre.gif" alt="We use the OGRE graphics library." /></a>
        <a href="http://validator.w3.org/check?uri=referer"><img src="buttons/w3c-xhtml1.1.gif" alt="This page validates as XHTML 1.1" /></a>
    </div>
    <div class="clear"></div>
    <div id="footer">
        Copyright © 2006 The Vega Strike Project. All Rights Reserved. Layout and Design by <a href="http://www.numbatsoftware.com/">Numbat Software</a>.
    </div>
</body>
</html>

