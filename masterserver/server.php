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


function checkv6($ip)
{
	$pattern1 = '([A-Fa-f0-9]{1,4}:){7}[A-Fa-f0-9]{1,4}';
	$pattern2 = '[A-Fa-f0-9]{0,4}::([A-Fa-f0-9]{1,4}:){0,5}[A-Fa-f0-9]{1,4}';
	$pattern3 = '([A-Fa-f0-9]{1,4}:){2}:([A-Fa-f0-9]{1,4}:){0,4}[A-Fa-f0-9]{1,4}';
	$pattern4 = '([A-Fa-f0-9]{1,4}:){3}:([A-Fa-f0-9]{1,4}:){0,3}[A-Fa-f0-9]{1,4}';
	$pattern5 = '([A-Fa-f0-9]{1,4}:){4}:([A-Fa-f0-9]{1,4}:){0,2}[A-Fa-f0-9]{1,4}';
	$pattern6 = '([A-Fa-f0-9]{1,4}:){5}:([A-Fa-f0-9]{1,4}:){0,1}[A-Fa-f0-9]{1,4}';
	$pattern7 = '([A-Fa-f0-9]{1,4}:){6}:[A-Fa-f0-9]{1,4}';
	$full = "/^($pattern1)$|^($pattern2)$|^($pattern3)$|^($pattern4)$|^($pattern5)$|^($pattern6)$|^($pattern7)$/";
	return (bool) preg_match($full,$ip);
}


$link = mysql_connect($database["host"], $database["user"], $database["password"]);
mysql_select_db($database["database"]);

$type = $_GET["type"];
if(isset($type))
{
	if ($type == "new" && isset($_POST["name"])&& isset($_POST["port"])&& isset($_POST["mod"])&& isset($_POST["maxplayers"]))
	{
 
		$name = mysql_real_escape_string($_POST["name"], $link);
		if ($_POST["password"] == "true")
		{
			$password = true;
		}
		elseif ($_POST["password"] == "false")
		{
			$password = false;
		}
		$port = mysql_real_escape_string($_POST["port"], $link);
		$mod = mysql_real_escape_string( $_POST["mod"], $link);
		$maxplayers = mysql_real_escape_string($_POST["maxplayers"], $link);
		$time = time();
		
		if (isset($_SERVER['HTTP_X_REMOTE_ADDR']))
		{
			$ip = $_SERVER['HTTP_X_REMOTE_ADDR'];
		}
		
		elseif (isset($_SERVER['REMOTE_ADDR']))
		{
			$ip = $_SERVER['REMOTE_ADDR'];
		}

		
		$ipv6 = checkv6($ip);
		$sesion_id = sha1(uniqid (rand()));
		$query = "INSERT INTO `serverlist` (
		`id` ,`name` , `session_id` , `ipadress` , `port` , `mod` , `password` , `maxplayers` , `currentplayers` , `singuptime` , `updatetime` , `ipv6`) 
		VALUES (NULL , '" . $name . "', '" . $sesion_id . "', '$ip', '". $port ."', '". $mod ."', '". $password ."', '" . $maxplayers . "', '0', '" . $time ."', '" . $time ."', '" . $ipv6 ."');";
		mysql_query($query);
		$body = "<NewServer>
	<name>" . $name . "</name>
	<sesion_id>" . $sesion_id . "</sesion_id>
	<timeoute>" . $timeout . "</timeout>
</NewServer>\n";
	}
	elseif ($type == "update" && isset($_POST["name"]) && isset($_POST["sesion_id"]) && isset($_POST["current_players"]))
	{
		$name = mysql_real_escape_string($_POST["name"], $link);
		$sesion_id = mysql_real_escape_string($_POST["sesion_id"], $link);
		$current_players = mysql_real_escape_string($_POST["current_players"], $link);
		$time = time();
		$query = "UPDATE serverlist SET currentplayers = '" . $current_players . "', updatetime = '" . $time . "' WHERE name = '" . $name . "' AND session_id = '" . $sesion_id . "' AND
		`updatetime` >=" . ($timeout + 1800);
		mysql_query($query);
		$body = "<ServerUpdate>
	<succes/>
</ServerUpdate>";
	}
}

echo "<?xml version=\"1.0\" encoding=\"UTF-8\" ?> \n";
echo $body . "\n"; 
mysql_close($link);
?>
