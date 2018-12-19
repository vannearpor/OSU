<!DOCTYPE html>
<html>
    <head>
    <meta charset="UTF-8">
        <title>NBA League Database</title>
        <link rel="stylesheet" href="css/style.css">
        <link rel="stylesheet" href="css/bootstrap.min.css">
        <link rel="stylesheet" href="css/bootstrap-theme.min.css">
        <script src="javascript/jquery.min.js"></script>
        <script src="javascript/bootstrap.min.js"></script>
    </head>
    <body>
        <div id="headline" class="jumbotron">
            <h1>NBA League Database</h1>
        </div>
        <div>
            <div class="container-fluid">
                <form action="nbaMain.php" method="POST">
                    Select a Player to see their profile: <select id = "playerDropdown" name = "playerDropdown">
<?php
    $servername = "classmysql.engr.oregonstate.edu";
    $username = "cs340_porv";
    $password = "4315";
    $dbname = "cs340_porv";

    $conn = new mysqli($servername, $username, $password, $dbname);

    if ($conn->connect_error) {
        die("Connection failed: " . $conn->connect_error);
    }
    $sql = "SELECT player_fname FROM player";
    $result = $conn->query($sql);
    while ($row = $result->fetch_assoc()) {
        unset($fname);
        $fname = $row['player_fname'];
        echo '<option value="'.$fname.'">'.$fname.'</option>';
    }
    $conn->close();
    ?>
</select>
<input name="playerChoose" type="submit" class="btn-primary" value="Player Chosen"/>
</form>
</div>
</div>
<div id="tableHolder">
<table class="table">
<tr>
<th>Player ID</th>
<th>Player</th>
<th>Player First Name</th>
<th>Player Last Name</th>
<th>Age</th>
<th>Experience</th>
<th>Team</th>
<th>Position</th>
</tr>
<tr>
<td>
<?php
    if(isset($_POST['playerChoose'])){
        $servername = "classmysql.engr.oregonstate.edu";
        $username = "cs340_porv";
        $password = "4315";
        $dbname = "cs340_porv";
        
        $fname = $_POST['playerDropdown'];

        $conn = new mysqli($servername, $username, $password, $dbname);

        $stmt = $conn->prepare('SELECT player_id FROM player WHERE player_fname=?');
        $stmt->bind_param('s', $fname);
        $stmt->execute();
        $stmt->bind_result($playerID);
        $results = $stmt->fetch();
        echo $playerID;
        $stmt->close();
        
        if ($conn->connect_error) {
            die("Connection failed: " . $conn->connect_error);
        }
        $conn->close();
    }
    ?>
</td>
<td>
<?php
    if(isset($_POST['playerChoose'])){
        echo $_POST['playerDropdown'];
    }
    ?>
</td>
<td>
<?php
    if(isset($_POST['playerChoose'])){
        $servername = "classmysql.engr.oregonstate.edu";
        $username = "cs340_porv";
        $password = "4315";
        $dbname = "cs340_porv";
        
        $name = $_POST['playerDropdown'];

        $conn = new mysqli($servername, $username, $password, $dbname);

        $stmt = $conn->prepare('SELECT player_fname FROM player WHERE player_fname=?');
        $stmt->bind_param('s', $fname);
        $stmt->execute();
        $stmt->bind_result($playerFN);
        $results = $stmt->fetch();
        echo $playerFN;
        $stmt->close();
        
        if ($conn->connect_error) {
            die("Connection failed: " . $conn->connect_error);
        }
        $conn->close();
    }
    ?>
</td>
<td>
<?php
    if(isset($_POST['playerChoose'])){
        $servername = "classmysql.engr.oregonstate.edu";
        $username = "cs340_porv";
        $password = "4315";
        $dbname = "cs340_porv";
        
        $name = $_POST['playerDropdown'];

        $conn = new mysqli($servername, $username, $password, $dbname);

        $stmt = $conn->prepare('SELECT player_lname FROM player WHERE player_fname=?');
        $stmt->bind_param('s', $fname);
        $stmt->execute();
        $stmt->bind_result($playerLN);
        $results = $stmt->fetch();
        echo $playerLN;
        $stmt->close();
        
        if ($conn->connect_error) {
            die("Connection failed: " . $conn->connect_error);
        }
        $conn->close();
    }
    ?>
</td>
<td>
<?php
    if(isset($_POST['playerChoose'])){
        $servername = "classmysql.engr.oregonstate.edu";
        $username = "cs340_porv";
        $password = "4315";
        $dbname = "cs340_porv";
        
        $name = $_POST['playerDropdown'];

        $conn = new mysqli($servername, $username, $password, $dbname);

        $stmt = $conn->prepare('SELECT age FROM player WHERE player_fname=?');
        $stmt->bind_param('s', $fname);
        $stmt->execute();
        $stmt->bind_result($playerAge);
        $results = $stmt->fetch();
        echo $playerAge;
        $stmt->close();
        
        if ($conn->connect_error) {
            die("Connection failed: " . $conn->connect_error);
        }
        $conn->close();
    }
    ?>
</td>
<td>
<?php
    if(isset($_POST['playerChoose'])){
        $servername = "classmysql.engr.oregonstate.edu";
        $username = "cs340_porv";
        $password = "4315";
        $dbname = "cs340_porv";
        
        $name = $_POST['playerDropdown'];

        $conn = new mysqli($servername, $username, $password, $dbname);

        $stmt = $conn->prepare('SELECT experience FROM player WHERE player_fname=?');
        $stmt->bind_param('s', $fname);
        $stmt->execute();
        $stmt->bind_result($playerEXP);
        $results = $stmt->fetch();
        echo $playerEXP;
        $stmt->close();
        
        if ($conn->connect_error) {
            die("Connection failed: " . $conn->connect_error);
        }
        $conn->close();
    }
    ?>
</td>
<td>
<?php
    if(isset($_POST['playerChoose'])){
        $servername = "classmysql.engr.oregonstate.edu";
        $username = "cs340_porv";
        $password = "4315";
        $dbname = "cs340_porv";
        
        $name = $_POST['playerChoose'];

        $conn = new mysqli($servername, $username, $password, $dbname);

        $stmt = $conn->prepare('SELECT team_name FROM team
                               INNER JOIN player_team
                               ON team.team_id = player_team.tid
                               INNER JOIN player
                               ON player_team.pid = player.player_id
                               WHERE player.player_fname = ?');
                               $stmt->bind_param('s', $fname);
                               $stmt->execute();
                               
                               if ($conn->connect_error) {
                               die("Connection failed: " . $conn->connect_error);
                               }
                               
                               
                               $team = "";
                               $stmt->bind_result($team);
                               
                               while ($stmt->fetch()) {
                               echo $team."<br>";
                               }
                               
                               $stmt->close();
                               $conn->close();
                               }
                               ?>
</td>
<td>
<?php
    if(isset($_POST['playerChoose'])){
        $servername = "classmysql.engr.oregonstate.edu";
        $username = "cs340_porv";
        $password = "4315";
        $dbname = "cs340_porv";
        
        $name = $_POST['playerChoose'];

        $conn = new mysqli($servername, $username, $password, $dbname);

        $stmt = $conn->prepare('SELECT pos_name FROM position
                               INNER JOIN player_position
                               ON position.position_id = player_position.pos_id
                               INNER JOIN player
                               ON player_position.pid = player.player_id
                               WHERE player.player_fname = ?');
                               $stmt->bind_param('s', $fname);
                               $stmt->execute();
                               
                               if ($conn->connect_error) {
                               die("Connection failed: " . $conn->connect_error);
                               }
                               
                               
                               $position = "";
                               $stmt->bind_result($position);
                               
                               while ($stmt->fetch()) {
                               echo $position."<br>";
                               }
                               
                               $stmt->close();
                               $conn->close();
                               }
                               ?>
</td></tr>
</table>
</div>
<hr>
<div>
<div class="container-fluid">
<form name="addPlayerForm" action='nbaQueries.php' method='POST'>
Add a new Player:<br>
First Name: <input type="text" id="playerfname" name ="playerfname" value="Player First Name" onfocus="if (this.value=='Player First Name') this.value='';"/>
Last Name: <input type="text" id="playerlname" name ="playerlname" value="Player Last Name" onfocus="if (this.value=='Player Last Name') this.value='';"/>
Age: <input type="number" id="playerage" name="playerage" value="Player Age" onfocus="if (this.value=='Player Age') this.value='';"/>
Experience: <input type="number" id="playerexperience" name="playerexperience" value="Player Experience" onfocus="if (this.value=='Player Experience') this.value='';"/>
<input name="addPlayer" type="submit" class="btn-primary" value="Add New Player"/>
</form>
</div>
</div>
<hr>
<div>
<div class="container-fluid">
<form action='nbaQueries.php' method = 'POST'>
Add Player to a Team:<br>
Player: <select id = "playerDropdown" name = "playerDropdown">
<?php
    $servername = "classmysql.engr.oregonstate.edu";
    $username = "cs340_porv";
    $password = "4315";
    $dbname = "cs340_porv";

    $conn = new mysqli($servername, $username, $password, $dbname);

    if ($conn->connect_error) {
        die("Connection failed: " . $conn->connect_error);
    }
    $sql = "SELECT player_fname FROM player";
    $result = $conn->query($sql);
    while ($row = $result->fetch_assoc()) {
        unset($fname);
        $fname = $row['player_fname'];
        echo '<option value="'.$fname.'">'.$fname.'</option>';
    }
    $conn->close();
    ?>
</select>
Team: <select id = "teamDropdown" name = "teamDropdown">
<?php
    $servername = "classmysql.engr.oregonstate.edu";
    $username = "cs340_porv";
    $password = "4315";
    $dbname = "cs340_porv";

    $conn = new mysqli($servername, $username, $password, $dbname);

    if ($conn->connect_error) {
        die("Connection failed: " . $conn->connect_error);
    }
    $sql = "SELECT team_name FROM team";
    $result = $conn->query($sql);
    while ($row = $result->fetch_assoc()) {
        unset($newTeam);
        $newTeam = $row['team_name'];
        echo '<option value="'.$newTeam.'">'.$newTeam.'</option>';
    }
    $conn->close();
    ?>
</select>
<input name="addTeam" type="submit" class="btn-primary" value="Update Roster"/>
</form>
</div>
</div>
<hr>
<div>
<div class="container-fluid">
<form action='nbaQueries.php' method = 'POST'>
Add Player to a Position:<br>
Player: <select id = "playerDropdown" name = "playerDropdown">
<?php
    $servername = "classmysql.engr.oregonstate.edu";
    $username = "cs340_porv";
    $password = "4315";
    $dbname = "cs340_porv";

    $conn = new mysqli($servername, $username, $password, $dbname);

    if ($conn->connect_error) {
        die("Connection failed: " . $conn->connect_error);
    }
    $sql = "SELECT player_fname FROM player";
    $result = $conn->query($sql);
    while ($row = $result->fetch_assoc()) {
        unset($fname);
        $fname = $row['player_fname'];
        echo '<option value="'.$fname.'">'.$fname.'</option>';
    }
    $conn->close();
    ?>
</select>Position: <select id = "positionDropdown" name = "positionDropdown">
<?php
    $servername = "classmysql.engr.oregonstate.edu";
    $username = "cs340_porv";
    $password = "4315";
    $dbname = "cs340_porv";

    $conn = new mysqli($servername, $username, $password, $dbname);

    if ($conn->connect_error) {
        die("Connection failed: " . $conn->connect_error);
    }
    $sql = "SELECT pos_name FROM position";
    $result = $conn->query($sql);
    while ($row = $result->fetch_assoc()) {
        unset($newPosition);
        $newPosition = $row['pos_name'];
        echo '<option value="'.$newPosition.'">'.$newPosition.'</option>';
    }
    $conn->close();
    ?>
</select>
<input name="addPosition" type="submit" class="btn-primary" value="Update Roster"/>
</form>
</div>
</div>
<hr>
<div>
<div class="container-fluid">
<form action='nbaQueries.php' method='POST'>
Delete a Player:<br>
Name: <select id = "playerDropdown" name = "playerDropdown">
<?php
    $servername = "classmysql.engr.oregonstate.edu";
    $username = "cs340_porv";
    $password = "4315";
    $dbname = "cs340_porv";

    $conn = new mysqli($servername, $username, $password, $dbname);

    if ($conn->connect_error) {
        die("Connection failed: " . $conn->connect_error);
    }
    $sql = "SELECT player_fname FROM player";
    $result = $conn->query($sql);
    while ($row = $result->fetch_assoc()) {
        unset($fname);
        $fname = $row['player_fname'];
        echo '<option value="'.$fname.'">'.$fname.'</option>';
    }
    $conn->close();
    ?>
</select>
<input name="deletePlayer" type="submit" class="btn-primary" value="Delete Player"/>
</form>
</div>
</div>
<hr>
<div>
<br/><br/>
</div>
</body>
</html>
