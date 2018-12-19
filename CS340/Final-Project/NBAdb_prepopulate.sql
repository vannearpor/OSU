-- ---------------------------------------------------------------
-- Prepopulating NBA League Database
-- using some of the existing NBA teams.
-- ---------------------------------------------------------------

-- ---------------------------------------------------------------
-- 'player'
-- (First Name, Last Name, Age, Experience)
-- ---------------------------------------------------------------

INSERT INTO player (player_fname, player_lname, age, experience) VALUES ("Kyrie", "Irving", 25, 6);
INSERT INTO player (player_fname, player_lname, age, experience) VALUES ("Jaylen", "Brown", 21, 1);
INSERT INTO player (player_fname, player_lname, age, experience) VALUES ("Jayson", "Tatum", 19, 0);
INSERT INTO player (player_fname, player_lname, age, experience) VALUES ("Gordon", "Hayward", 27, 7);
INSERT INTO player (player_fname, player_lname, age, experience) VALUES ("Al", "Horford", 31, 10);
INSERT INTO player (player_fname, player_lname, age, experience) VALUES ("Derrick", "Rose", 29, 8);
INSERT INTO player (player_fname, player_lname, age, experience) VALUES ("Dwayne", "Wade", 35, 14);
INSERT INTO player (player_fname, player_lname, age, experience) VALUES ("LeBron", "James", 32, 14);
INSERT INTO player (player_fname, player_lname, age, experience) VALUES ("Jae", "Crowder", 27, 5);
INSERT INTO player (player_fname, player_lname, age, experience) VALUES ("Tristan", "Thompson", 26, 6);
INSERT INTO player (player_fname, player_lname, age, experience) VALUES ("Darren", "Collison", 30, 8);
INSERT INTO player (player_fname, player_lname, age, experience) VALUES ("Victor", "Oladipo", 25, 4);
INSERT INTO player (player_fname, player_lname, age, experience) VALUES ("Bojan", "Bogdanovic", 28, 3);
INSERT INTO player (player_fname, player_lname, age, experience) VALUES ("Thaddeus", "Young", 29, 10);
INSERT INTO player (player_fname, player_lname, age, experience) VALUES ("Myles", "Turner", 21, 2);
INSERT INTO player (player_fname, player_lname, age, experience) VALUES ("Chris", "Paul", 32, 12);
INSERT INTO player (player_fname, player_lname, age, experience) VALUES ("James", "Harden", 28, 8);
INSERT INTO player (player_fname, player_lname, age, experience) VALUES ("Trevor", "Ariza", 32, 13);
INSERT INTO player (player_fname, player_lname, age, experience) VALUES ("Ryan", "Anderson", 29, 9);
INSERT INTO player (player_fname, player_lname, age, experience) VALUES ("Clint", "Capela", 23, 3);
INSERT INTO player (player_fname, player_lname, age, experience) VALUES ("Stephen", "Curry", 29, 8);
INSERT INTO player (player_fname, player_lname, age, experience) VALUES ("Klay", "Thompson", 27, 6);
INSERT INTO player (player_fname, player_lname, age, experience) VALUES ("Kevin", "Durant", 29, 10);
INSERT INTO player (player_fname, player_lname, age, experience) VALUES ("Draymond", "Green", 27, 5);
INSERT INTO player (player_fname, player_lname, age, experience) VALUES ("Zaza", "Pachulia", 33, 14);
INSERT INTO player (player_fname, player_lname, age, experience) VALUES ("Jeff", "Teague", 29, 8);
INSERT INTO player (player_fname, player_lname, age, experience) VALUES ("Jimmy", "Butler", 28, 6);
INSERT INTO player (player_fname, player_lname, age, experience) VALUES ("Andrew", "Wiggins", 22, 3);
INSERT INTO player (player_fname, player_lname, age, experience) VALUES ("Taj", "Gibson", 32, 8);
INSERT INTO player (player_fname, player_lname, age, experience) VALUES ("Karl-Anthony", "Towns", 22, 2);

-- ----------------------------------------------------------------
-- 'team'
-- (Team Name, City, Number of Titles)
-- ----------------------------------------------------------------

INSERT INTO team (team_name, city, num_titles) VALUES ("Celtics", "Boston", 17);
INSERT INTO team (team_name, city, num_titles) VALUES ("Cavaliers", "Cleveland", 1);
INSERT INTO team (team_name, city, num_titles) VALUES ("Pacers", "Indiana", 0);
INSERT INTO team (team_name, city, num_titles) VALUES ("Rockets", "Houston", 2);
INSERT INTO team (team_name, city, num_titles) VALUES ("Warriors", "Golden State", 5);
INSERT INTO team (team_name, city, num_titles) VALUES ("Timberwolves", "Minnesota", 0);

-- ----------------------------------------------------------------
-- 'league_division'
-- (Division Name, Number of Teams)
-- ----------------------------------------------------------------

INSERT INTO league_division (div_name, num_teams) VALUES ("East", 3);
INSERT INTO league_division (div_name, num_teams) VALUES ("West", 3);

-- -----------------------------------------------------------------
-- 'position'
-- (Position Name)
-- -----------------------------------------------------------------

INSERT INTO position (pos_name) VALUES ("Point Guard");
INSERT INTO position (pos_name) VALUES ("Shooting Guard");
INSERT INTO position (pos_name) VALUES ("Small Forward");
INSERT INTO position (pos_name) VALUES ("Power Forward");
INSERT INTO position (pos_name) VALUES ("Center");

-- -----------------------------------------------------------------
-- 'team_division'
-- (Division ID, Team ID)
-- -----------------------------------------------------------------

INSERT INTO team_division (division_pid, tid) VALUES ((SELECT league_id FROM league_division WHERE div_name = "East"), (SELECT team_id FROM team WHERE team_name = "Celtics"));
INSERT INTO team_division (division_pid, tid) VALUES ((SELECT league_id FROM league_division WHERE div_name = "East"), (SELECT team_id FROM team WHERE team_name = "Cavaliers"));
INSERT INTO team_division (division_pid, tid) VALUES ((SELECT league_id FROM league_division WHERE div_name = "East"), (SELECT team_id FROM team WHERE team_name = "Pacers"));
INSERT INTO team_division (division_pid, tid) VALUES ((SELECT league_id FROM league_division WHERE div_name = "West"), (SELECT team_id FROM team WHERE team_name = "Rockets"));
INSERT INTO team_division (division_pid, tid) VALUES ((SELECT league_id FROM league_division WHERE div_name = "West"), (SELECT team_id FROM team WHERE team_name = "Warriors"));
INSERT INTO team_division (division_pid, tid) VALUES ((SELECT league_id FROM league_division WHERE div_name = "West"), (SELECT team_id FROM team WHERE team_name = "Timberwolves"));

-- -----------------------------------------------------------------
-- 'player_division'
-- (Division ID, Player ID)
-- -----------------------------------------------------------------

INSERT INTO player_division (division_pid, pid) VALUES ((SELECT league_id FROM league_division WHERE div_name = "East"), (SELECT player_id FROM player WHERE player_fname = "Kyrie"));
INSERT INTO player_division (division_pid, pid) VALUES ((SELECT league_id FROM league_division WHERE div_name = "East"), (SELECT player_id FROM player WHERE player_fname = "Jaylen"));
INSERT INTO player_division (division_pid, pid) VALUES ((SELECT league_id FROM league_division WHERE div_name = "East"), (SELECT player_id FROM player WHERE player_fname = "Jayson"));
INSERT INTO player_division (division_pid, pid) VALUES ((SELECT league_id FROM league_division WHERE div_name = "East"), (SELECT player_id FROM player WHERE player_fname = "Gordon"));
INSERT INTO player_division (division_pid, pid) VALUES ((SELECT league_id FROM league_division WHERE div_name = "East"), (SELECT player_id FROM player WHERE player_fname = "Al"));
INSERT INTO player_division (division_pid, pid) VALUES ((SELECT league_id FROM league_division WHERE div_name = "East"), (SELECT player_id FROM player WHERE player_fname = "Derrick"));
INSERT INTO player_division (division_pid, pid) VALUES ((SELECT league_id FROM league_division WHERE div_name = "East"), (SELECT player_id FROM player WHERE player_fname = "Dwayne"));
INSERT INTO player_division (division_pid, pid) VALUES ((SELECT league_id FROM league_division WHERE div_name = "East"), (SELECT player_id FROM player WHERE player_fname = "LeBron"));
INSERT INTO player_division (division_pid, pid) VALUES ((SELECT league_id FROM league_division WHERE div_name = "East"), (SELECT player_id FROM player WHERE player_fname = "Jae"));
INSERT INTO player_division (division_pid, pid) VALUES ((SELECT league_id FROM league_division WHERE div_name = "East"), (SELECT player_id FROM player WHERE player_fname = "Tristan"));
INSERT INTO player_division (division_pid, pid) VALUES ((SELECT league_id FROM league_division WHERE div_name = "East"), (SELECT player_id FROM player WHERE player_fname = "Darren"));
INSERT INTO player_division (division_pid, pid) VALUES ((SELECT league_id FROM league_division WHERE div_name = "East"), (SELECT player_id FROM player WHERE player_fname = "Victor"));
INSERT INTO player_division (division_pid, pid) VALUES ((SELECT league_id FROM league_division WHERE div_name = "East"), (SELECT player_id FROM player WHERE player_fname = "Bojan"));
INSERT INTO player_division (division_pid, pid) VALUES ((SELECT league_id FROM league_division WHERE div_name = "East"), (SELECT player_id FROM player WHERE player_fname = "Thaddeus"));
INSERT INTO player_division (division_pid, pid) VALUES ((SELECT league_id FROM league_division WHERE div_name = "East"), (SELECT player_id FROM player WHERE player_fname = "Myles"));
INSERT INTO player_division (division_pid, pid) VALUES ((SELECT league_id FROM league_division WHERE div_name = "West"), (SELECT player_id FROM player WHERE player_fname = "Chris"));
INSERT INTO player_division (division_pid, pid) VALUES ((SELECT league_id FROM league_division WHERE div_name = "West"), (SELECT player_id FROM player WHERE player_fname = "James"));
INSERT INTO player_division (division_pid, pid) VALUES ((SELECT league_id FROM league_division WHERE div_name = "West"), (SELECT player_id FROM player WHERE player_fname = "Trevor"));
INSERT INTO player_division (division_pid, pid) VALUES ((SELECT league_id FROM league_division WHERE div_name = "West"), (SELECT player_id FROM player WHERE player_fname = "Ryan"));
INSERT INTO player_division (division_pid, pid) VALUES ((SELECT league_id FROM league_division WHERE div_name = "West"), (SELECT player_id FROM player WHERE player_fname = "Clint"));
INSERT INTO player_division (division_pid, pid) VALUES ((SELECT league_id FROM league_division WHERE div_name = "West"), (SELECT player_id FROM player WHERE player_fname = "Stephen"));
INSERT INTO player_division (division_pid, pid) VALUES ((SELECT league_id FROM league_division WHERE div_name = "West"), (SELECT player_id FROM player WHERE player_fname = "Klay"));
INSERT INTO player_division (division_pid, pid) VALUES ((SELECT league_id FROM league_division WHERE div_name = "West"), (SELECT player_id FROM player WHERE player_fname = "Kevin"));
INSERT INTO player_division (division_pid, pid) VALUES ((SELECT league_id FROM league_division WHERE div_name = "West"), (SELECT player_id FROM player WHERE player_fname = "Draymond"));
INSERT INTO player_division (division_pid, pid) VALUES ((SELECT league_id FROM league_division WHERE div_name = "West"), (SELECT player_id FROM player WHERE player_fname = "Zaza"));
INSERT INTO player_division (division_pid, pid) VALUES ((SELECT league_id FROM league_division WHERE div_name = "West"), (SELECT player_id FROM player WHERE player_fname = "Jeff"));
INSERT INTO player_division (division_pid, pid) VALUES ((SELECT league_id FROM league_division WHERE div_name = "West"), (SELECT player_id FROM player WHERE player_fname = "Jimmy"));
INSERT INTO player_division (division_pid, pid) VALUES ((SELECT league_id FROM league_division WHERE div_name = "West"), (SELECT player_id FROM player WHERE player_fname = "Andrew"));
INSERT INTO player_division (division_pid, pid) VALUES ((SELECT league_id FROM league_division WHERE div_name = "West"), (SELECT player_id FROM player WHERE player_fname = "Taj"));
INSERT INTO player_division (division_pid, pid) VALUES ((SELECT league_id FROM league_division WHERE div_name = "West"), (SELECT player_id FROM player WHERE player_fname = "Karl-Anthony"));

-- -----------------------------------------------------------------
-- 'player_position'
-- (Player ID, Position ID)
-- -----------------------------------------------------------------

INSERT INTO player_position (pid, pos_id) VALUES ((SELECT player_id FROM player WHERE player_fname = "Kyrie"), (SELECT position_id FROM position WHERE pos_name = "Point Guard"));
INSERT INTO player_position (pid, pos_id) VALUES ((SELECT player_id FROM player WHERE player_fname = "Jaylen"), (SELECT position_id FROM position WHERE pos_name = "Shooting Guard"));
INSERT INTO player_position (pid, pos_id) VALUES ((SELECT player_id FROM player WHERE player_fname = "Jayson"), (SELECT position_id FROM position WHERE pos_name = "Small Forward"));
INSERT INTO player_position (pid, pos_id) VALUES ((SELECT player_id FROM player WHERE player_fname = "Gordon"), (SELECT position_id FROM position WHERE pos_name = "Power Forward"));
INSERT INTO player_position (pid, pos_id) VALUES ((SELECT player_id FROM player WHERE player_fname = "Al"), (SELECT position_id FROM position WHERE pos_name = "Center"));
INSERT INTO player_position (pid, pos_id) VALUES ((SELECT player_id FROM player WHERE player_fname = "Derrick"), (SELECT position_id FROM position WHERE pos_name = "Point Guard"));
INSERT INTO player_position (pid, pos_id) VALUES ((SELECT player_id FROM player WHERE player_fname = "Dwayne"), (SELECT position_id FROM position WHERE pos_name = "Shooting Guard"));
INSERT INTO player_position (pid, pos_id) VALUES ((SELECT player_id FROM player WHERE player_fname = "LeBron"), (SELECT position_id FROM position WHERE pos_name = "Small Forward"));
INSERT INTO player_position (pid, pos_id) VALUES ((SELECT player_id FROM player WHERE player_fname = "Jae"), (SELECT position_id FROM position WHERE pos_name = "Power Forward"));
INSERT INTO player_position (pid, pos_id) VALUES ((SELECT player_id FROM player WHERE player_fname = "Tristan"), (SELECT position_id FROM position WHERE pos_name = "Center"));
INSERT INTO player_position (pid, pos_id) VALUES ((SELECT player_id FROM player WHERE player_fname = "Darren"), (SELECT position_id FROM position WHERE pos_name = "Point Guard"));
INSERT INTO player_position (pid, pos_id) VALUES ((SELECT player_id FROM player WHERE player_fname = "Victor"), (SELECT position_id FROM position WHERE pos_name = "Shooting Guard"));
INSERT INTO player_position (pid, pos_id) VALUES ((SELECT player_id FROM player WHERE player_fname = "Bojan"), (SELECT position_id FROM position WHERE pos_name = "Small Forward"));
INSERT INTO player_position (pid, pos_id) VALUES ((SELECT player_id FROM player WHERE player_fname = "Thaddeus"), (SELECT position_id FROM position WHERE pos_name = "Power Forward"));
INSERT INTO player_position (pid, pos_id) VALUES ((SELECT player_id FROM player WHERE player_fname = "Myles"), (SELECT position_id FROM position WHERE pos_name = "Center"));
INSERT INTO player_position (pid, pos_id) VALUES ((SELECT player_id FROM player WHERE player_fname = "Chris"), (SELECT position_id FROM position WHERE pos_name = "Point Guard"));
INSERT INTO player_position (pid, pos_id) VALUES ((SELECT player_id FROM player WHERE player_fname = "James"), (SELECT position_id FROM position WHERE pos_name = "Shooting Guard"));
INSERT INTO player_position (pid, pos_id) VALUES ((SELECT player_id FROM player WHERE player_fname = "Trevor"), (SELECT position_id FROM position WHERE pos_name = "Small Forward"));
INSERT INTO player_position (pid, pos_id) VALUES ((SELECT player_id FROM player WHERE player_fname = "Ryan"), (SELECT position_id FROM position WHERE pos_name = "Power Forward"));
INSERT INTO player_position (pid, pos_id) VALUES ((SELECT player_id FROM player WHERE player_fname = "Clint"), (SELECT position_id FROM position WHERE pos_name = "Center"));
INSERT INTO player_position (pid, pos_id) VALUES ((SELECT player_id FROM player WHERE player_fname = "Stephen"), (SELECT position_id FROM position WHERE pos_name = "Point Guard"));
INSERT INTO player_position (pid, pos_id) VALUES ((SELECT player_id FROM player WHERE player_fname = "Klay"), (SELECT position_id FROM position WHERE pos_name = "Shooting Guard"));
INSERT INTO player_position (pid, pos_id) VALUES ((SELECT player_id FROM player WHERE player_fname = "Kevin"), (SELECT position_id FROM position WHERE pos_name = "Small Forward"));
INSERT INTO player_position (pid, pos_id) VALUES ((SELECT player_id FROM player WHERE player_fname = "Draymond"), (SELECT position_id FROM position WHERE pos_name = "Power Forward"));
INSERT INTO player_position (pid, pos_id) VALUES ((SELECT player_id FROM player WHERE player_fname = "Zaza"), (SELECT position_id FROM position WHERE pos_name = "Center"));
INSERT INTO player_position (pid, pos_id) VALUES ((SELECT player_id FROM player WHERE player_fname = "Jeff"), (SELECT position_id FROM position WHERE pos_name = "Point Guard"));
INSERT INTO player_position (pid, pos_id) VALUES ((SELECT player_id FROM player WHERE player_fname = "Jimmy"), (SELECT position_id FROM position WHERE pos_name = "Shooting Guard"));
INSERT INTO player_position (pid, pos_id) VALUES ((SELECT player_id FROM player WHERE player_fname = "Andrew"), (SELECT position_id FROM position WHERE pos_name = "Small Forward"));
INSERT INTO player_position (pid, pos_id) VALUES ((SELECT player_id FROM player WHERE player_fname = "Taj"), (SELECT position_id FROM position WHERE pos_name = "Power Forward"));
INSERT INTO player_position (pid, pos_id) VALUES ((SELECT player_id FROM player WHERE player_fname = "Karl-Anthony"), (SELECT position_id FROM position WHERE pos_name = "Center"));

-- -----------------------------------------------------------------
-- 'player_team'
-- (Player ID, Team ID)
-- -----------------------------------------------------------------

INSERT INTO player_team (pid, tid) VALUES ((SELECT player_id FROM player WHERE player_fname = "Kyrie"), (SELECT team_id FROM team WHERE team_name = "Celtics"));
INSERT INTO player_team (pid, tid) VALUES ((SELECT player_id FROM player WHERE player_fname = "Jaylen"), (SELECT team_id FROM team WHERE team_name = "Celtics"));
INSERT INTO player_team (pid, tid) VALUES ((SELECT player_id FROM player WHERE player_fname = "Jayson"), (SELECT team_id FROM team WHERE team_name = "Celtics"));
INSERT INTO player_team (pid, tid) VALUES ((SELECT player_id FROM player WHERE player_fname = "Gordon"), (SELECT team_id FROM team WHERE team_name = "Celtics"));
INSERT INTO player_team (pid, tid) VALUES ((SELECT player_id FROM player WHERE player_fname = "Al"), (SELECT team_id FROM team WHERE team_name = "Celtics"));
INSERT INTO player_team (pid, tid) VALUES ((SELECT player_id FROM player WHERE player_fname = "Derrick"), (SELECT team_id FROM team WHERE team_name = "Cavaliers"));
INSERT INTO player_team (pid, tid) VALUES ((SELECT player_id FROM player WHERE player_fname = "Dwayne"), (SELECT team_id FROM team WHERE team_name = "Cavaliers"));
INSERT INTO player_team (pid, tid) VALUES ((SELECT player_id FROM player WHERE player_fname = "LeBron"), (SELECT team_id FROM team WHERE team_name = "Cavaliers"));
INSERT INTO player_team (pid, tid) VALUES ((SELECT player_id FROM player WHERE player_fname = "Jae"), (SELECT team_id FROM team WHERE team_name = "Cavaliers"));
INSERT INTO player_team (pid, tid) VALUES ((SELECT player_id FROM player WHERE player_fname = "Tristan"), (SELECT team_id FROM team WHERE team_name = "Cavaliers"));
INSERT INTO player_team (pid, tid) VALUES ((SELECT player_id FROM player WHERE player_fname = "Darren"), (SELECT team_id FROM team WHERE team_name = "Pacers"));
INSERT INTO player_team (pid, tid) VALUES ((SELECT player_id FROM player WHERE player_fname = "Victor"), (SELECT team_id FROM team WHERE team_name = "Pacers"));
INSERT INTO player_team (pid, tid) VALUES ((SELECT player_id FROM player WHERE player_fname = "Bojan"), (SELECT team_id FROM team WHERE team_name = "Pacers"));
INSERT INTO player_team (pid, tid) VALUES ((SELECT player_id FROM player WHERE player_fname = "Thaddeus"), (SELECT team_id FROM team WHERE team_name = "Pacers"));
INSERT INTO player_team (pid, tid) VALUES ((SELECT player_id FROM player WHERE player_fname = "Myles"), (SELECT team_id FROM team WHERE team_name = "Pacers"));
INSERT INTO player_team (pid, tid) VALUES ((SELECT player_id FROM player WHERE player_fname = "Chris"), (SELECT team_id FROM team WHERE team_name = "Rockets"));
INSERT INTO player_team (pid, tid) VALUES ((SELECT player_id FROM player WHERE player_fname = "James"), (SELECT team_id FROM team WHERE team_name = "Rockets"));
INSERT INTO player_team (pid, tid) VALUES ((SELECT player_id FROM player WHERE player_fname = "Trevor"), (SELECT team_id FROM team WHERE team_name = "Rockets"));
INSERT INTO player_team (pid, tid) VALUES ((SELECT player_id FROM player WHERE player_fname = "Ryan"), (SELECT team_id FROM team WHERE team_name = "Rockets"));
INSERT INTO player_team (pid, tid) VALUES ((SELECT player_id FROM player WHERE player_fname = "Clint"), (SELECT team_id FROM team WHERE team_name = "Rockets"));
INSERT INTO player_team (pid, tid) VALUES ((SELECT player_id FROM player WHERE player_fname = "Stephen"), (SELECT team_id FROM team WHERE team_name = "Warriors"));
INSERT INTO player_team (pid, tid) VALUES ((SELECT player_id FROM player WHERE player_fname = "Klay"), (SELECT team_id FROM team WHERE team_name = "Warriors"));
INSERT INTO player_team (pid, tid) VALUES ((SELECT player_id FROM player WHERE player_fname = "Kevin"), (SELECT team_id FROM team WHERE team_name = "Warriors"));
INSERT INTO player_team (pid, tid) VALUES ((SELECT player_id FROM player WHERE player_fname = "Draymond"), (SELECT team_id FROM team WHERE team_name = "Warriors"));
INSERT INTO player_team (pid, tid) VALUES ((SELECT player_id FROM player WHERE player_fname = "Zaza"), (SELECT team_id FROM team WHERE team_name = "Warriors"));
INSERT INTO player_team (pid, tid) VALUES ((SELECT player_id FROM player WHERE player_fname = "Jeff"), (SELECT team_id FROM team WHERE team_name = "Timberwolves"));
INSERT INTO player_team (pid, tid) VALUES ((SELECT player_id FROM player WHERE player_fname = "Jimmy"), (SELECT team_id FROM team WHERE team_name = "Timberwolves"));
INSERT INTO player_team (pid, tid) VALUES ((SELECT player_id FROM player WHERE player_fname = "Andrew"), (SELECT team_id FROM team WHERE team_name = "Timberwolves"));
INSERT INTO player_team (pid, tid) VALUES ((SELECT player_id FROM player WHERE player_fname = "Taj"), (SELECT team_id FROM team WHERE team_name = "Timberwolves"));
INSERT INTO player_team (pid, tid) VALUES ((SELECT player_id FROM player WHERE player_fname = "Karl-Anthony"), (SELECT team_id FROM team WHERE team_name = "Timberwolves"));
