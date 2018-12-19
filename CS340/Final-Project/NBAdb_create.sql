-- ------------------------------------------------------
-- NBA Database
-- ------------------------------------------------------

DROP TABLE IF EXISTS `player_team`;
DROP TABLE IF EXISTS `player_position`;
DROP TABLE IF EXISTS `player_division`;
DROP TABLE IF EXISTS `team_division`;
DROP TABLE IF EXISTS `player`;
DROP TABLE IF EXISTS `team`;
DROP TABLE IF EXISTS `league_division`;
DROP TABLE IF EXISTS `position`;

-- ------------------------------------------------------
-- Players in the League
-- ------------------------------------------------------

CREATE TABLE `player` (
		`player_id` int(11) NOT NULL AUTO_INCREMENT,
        `player_fname` varchar(255) NOT NULL,
        `player_lname` varchar(255) NOT NULL,
        `age` int(11) NOT NULL,
        `experience` int(11) NOT NULL,
        PRIMARY KEY (`player_id`)
) ENGINE=InnoDB;

-- ------------------------------------------------------
-- Teams in the League
-- ------------------------------------------------------

CREATE TABLE `team` (
		`team_id` int(11) NOT NULL AUTO_INCREMENT,
        `team_name` varchar(255) NOT NULL,
        `city` varchar(255) NOT NULL,
        `num_titles` int(11),
        PRIMARY KEY (`team_id`),
        UNIQUE KEY (`team_name`)
) ENGINE=InnoDB;

-- ------------------------------------------------------
-- Divisions in the League
-- ------------------------------------------------------

CREATE TABLE `league_division` (
		`league_id` int(11) NOT NULL AUTO_INCREMENT,
        `div_name` varchar(255) NOT NULL,
        `num_teams` int(11) NOT NULL,
        PRIMARY KEY (`league_id`),
        UNIQUE KEY (`div_name`)
) ENGINE=InnoDB;

-- ------------------------------------------------------
-- Positions that Players play
-- ------------------------------------------------------

CREATE TABLE `position` (
		`position_id` int(11) NOT NULL AUTO_INCREMENT,
		`pos_name` varchar(255) NOT NULL,
        PRIMARY KEY (`position_id`),
        UNIQUE KEY (`pos_name`)
) ENGINE=InnoDB;

-- ------------------------------------------------------
-- Teams belong to a Division
-- One-to-many relationship (One Division; Many Teams)
-- ------------------------------------------------------

CREATE TABLE `team_division` (
		`division_pid` int(11) NOT NULL,
        `tid` int(11) NOT NULL,
        PRIMARY KEY (`division_pid`, `tid`),
        FOREIGN KEY (`division_pid`) REFERENCES `league_division` (`league_id`)
				ON DELETE CASCADE
                ON UPDATE CASCADE,
		FOREIGN KEY (`tid`) REFERENCES `team` (`team_id`)
				ON DELETE CASCADE
                ON UPDATE CASCADE
) ENGINE=InnoDB;

-- -------------------------------------------------------
-- Players belong to a Division
-- One-to-many relationsjhip (One Division; Many Players)
-- -------------------------------------------------------

CREATE TABLE `player_division` (
		`division_pid` int(11) NOT NULL,
        `pid` int(11) NOT NULL,
        PRIMARY KEY (`division_pid`, `pid`),
        FOREIGN KEY (`division_pid`) REFERENCES `league_division` (`league_id`)
				ON DELETE CASCADE
                ON UPDATE CASCADE,
		FOREIGN KEY (`pid`) REFERENCES `player` (`player_id`)
				ON DELETE CASCADE
                ON UPDATE CASCADE
) ENGINE=InnoDB;

-- ----------------------------------------------------------
-- Players fit into a role of Positions
-- Many-to-many relationship (Many Players Can Play Many Positions)
-- ----------------------------------------------------------

CREATE TABLE `player_position` (
		`pid` int(11) NOT NULL,
        `pos_id` int(11) NOT NULL,
        PRIMARY KEY (`pid`, `pos_id`),
        FOREIGN KEY (`pid`) REFERENCES `player` (`player_id`)
				ON DELETE CASCADE
                ON UPDATE CASCADE,
		FOREIGN KEY (`pos_id`) REFERENCES `position` (`position_id`)
				ON DELETE CASCADE
                ON UPDATE CASCADE
) ENGINE=InnoDB;

-- ----------------------------------------------------------
-- Players belong on a Team
-- One-to-many relationship (One Team; Many Players)
-- ----------------------------------------------------------

CREATE TABLE `player_team` (
		`pid` int(11) NOT NULL,
        `tid` int(11) NOT NULL,
        PRIMARY KEY (`pid`, `tid`),
        FOREIGN KEY (`pid`) REFERENCES `player` (`player_id`)
				ON DELETE CASCADE
                ON UPDATE CASCADE,
		FOREIGN KEY (`tid`) REFERENCES `team` (`team_id`)
				ON DELETE CASCADE
                ON UPDATE CASCADE
) ENGINE=InnoDB;

