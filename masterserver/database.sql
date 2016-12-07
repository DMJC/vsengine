CREATE TABLE `serverlist` (
  `id` int(11) NOT NULL auto_increment,
  `name` text NOT NULL,
  `session_id` text NOT NULL,
  `ipadress` varchar(40) NOT NULL,
  `port` int(11) NOT NULL,
  `mod` text NOT NULL,
  `password` tinyint(1) NOT NULL,
  `maxplayers` int(11) NOT NULL,
  `currentplayers` int(11) NOT NULL,
  `singuptime` int(11) NOT NULL,
  `updatetime` int(11) NOT NULL,
  `ipv6` tinyint(1) NOT NULL,
  UNIQUE KEY `id` (`id`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=5 ;
