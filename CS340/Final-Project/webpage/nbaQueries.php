<?php
    if(isset($_POST['addPlayer'])){
        $servername = "classmysql.engr.oregonstate.edu";
        $username = "cs340_porv";
        $password = "4315";
        $dbname = "cs340_porv";
        
        
        $fname = $_POST['playerfname'];
        $lname = $_POST['playerlname'];
        $age = $_POST['playerage'];
        $exp = $_POST['playerexperience'];

        $conn = new mysqli($servername, $username, $password, $dbname);
        $stmt = $conn->prepare('INSERT INTO player (player_fname, player_lname, age, experience) VALUES (?, ?, ?, ?)');
        $stmt->bind_param('ssii', $fname, $lname, $age, $exp);
        $stmt->execute();
        $stmt->close();
        
        if ($conn->connect_error) {
            die("Connection failed: " . $conn->connect_error);
        }
        $conn->close();
    }
    if(isset($_POST['addTeam'])){
        $servername = "classmysql.engr.oregonstate.edu";
        $username = "cs340_porv";
        $password = "4315";
        $dbname = "cs340_porv";
        

        $fname = $_POST['playerDropdown'];
        $newTeam = $_POST['teamDropdown'];

        $conn = new mysqli($servername, $username, $password, $dbname);
        $stmt = $conn->prepare('SELECT player_id FROM player WHERE player_name = (?)');
        $stmt->bind_param('s', $fname);
        $stmt->execute();
        $stmt->bind_result($playerid);
        $results = $stmt->fetch();
        
        $conn2 = new mysqli($servername, $username, $password, $dbname);
        $stmt = $conn2->prepare('SELECT team_id FROM team WHERE team_name = (?)');
        $stmt->bind_param('s', $newTeam);
        $stmt->execute();
        $stmt->bind_result($teamid);
        $results = $stmt->fetch();
        
        $conn3 = new mysqli($servername, $username, $password, $dbname);
        $stmt = $conn3->prepare('INSERT INTO player_team (pid, tid) VALUES (?, ?)');
        $stmt->bind_param('ss', $playerid, $teamid);
        
        $stmt->execute();
        $stmt->close();
        
        if ($conn->connect_error) {
            die("Connection failed: " . $conn->connect_error);
        }
        $conn->close();
    }
    
    if(isset($_POST['addPosition'])){
        $servername = "classmysql.engr.oregonstate.edu";
        $username = "cs340_porv";
        $password = "4315";
        $dbname = "cs340_porv";
        
        
        $fname = $_POST['playerDropdown'];
        $newPosition = $_POST['positionDropdown'];

        $conn = new mysqli($servername, $username, $password, $dbname);
        $stmt = $conn->prepare('SELECT player_id FROM player WHERE player_name = (?)');
        $stmt->bind_param('i', $fname);
        $stmt->execute();
        $stmt->bind_result($playerid);
        $results = $stmt->fetch();
        
        $conn2 = new mysqli($servername, $username, $password, $dbname);
        $stmt = $conn2->prepare('SELECT position_id FROM position WHERE pos_name = (?)');
        $stmt->bind_param('i', $newPosition);
        $stmt->execute();
        $stmt->bind_result($positionid);
        $results = $stmt->fetch();
        
        $conn3 = new mysqli($servername, $username, $password, $dbname);
        $stmt = $conn3->prepare('INSERT INTO player_position (pid, pos_id) VALUES (?, ?)');
        $stmt->bind_param('ii', $playerid, $positionid);
        
        $stmt->execute();
        $stmt->close();
        
        if ($conn->connect_error) {
            die("Connection failed: " . $conn->connect_error);
        }
        $conn->close();
    }
    
    if(isset($_POST['deletePlayer'])){
        $servername = "classmysql.engr.oregonstate.edu";
        $username = "cs340_porv";
        $password = "4315";
        $dbname = "cs340_porv";
        

        
        $fname = $_POST['playerDropdown'];
        $conn = new mysqli($servername, $username, $password, $dbname);
        $stmt = $conn->prepare('DELETE FROM player WHERE player_fname = ?');
        $stmt->bind_param('s', $fname);
        
        $stmt->execute();
        $stmt->close();
        
        if ($conn->connect_error) {
            die("Connection failed: " . $conn->connect_error);
        }
        $conn->close();
    }
    
    header("Location:nbaMain.php");
    exit();
    ?>
