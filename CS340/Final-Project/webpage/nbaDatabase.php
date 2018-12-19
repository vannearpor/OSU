<?php
    $servername = "classmysql.engr.oregonstate.edu";
    $username = "cs340_porv";
    $password = "4315";
    $dbname = "cs340_porv";

    $conn = new mysqli($servername, $username, $password, $dbname);

    if ($conn->connect_error) {
        die("Connection failed: " . $conn->connect_error);
    }
    $sql = "SELECT player_id, player_fname, player_lname, age, experience FROM player";
    $result = $conn->query($sql);
    if ($result->num_rows > 0) {
        echo '<table cellpadding="1" cellspacing="0.5" class="player-table" border="solid">';
        echo '<tr><th>Player</th><th>First Name</th><th>Last Name</th><th>Age</th><th>Experience</th></tr>';
        while($row = $result->fetch_assoc()) {
            echo '<tr>';
            foreach($row as $key=>$value) {
                echo '<td>',$value,'</td>';
            }
            echo '</tr>';
        }
        echo '</table><br />';
    } else {
        echo "0 results";
    }
    $conn->close();
    ?>
