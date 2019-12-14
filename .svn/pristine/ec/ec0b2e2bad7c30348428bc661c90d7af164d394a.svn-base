<?php
include_once '../common/class.common.user.inc';

/*class User{

    private $_ID;

    public function setID ( $ID ) {
        $this->_ID = $ID;
    }

    public function getID () {
        return $this->_ID;
    }
}*/

if (session_status() == PHP_SESSION_NONE) {
    session_start();
}

$servername = "localhost";
$username = "root";
$password = "";
$dbname = "cseku";

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);
// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
} 

$data = array();


/*fetch the user id to show their discipline events*/
$ID = $_SESSION['globalUser']->getID();

$SQL3 = "SELECT RoleID FROM ums_user_role WHERE UserID = '$ID'";
$statement3 = $conn->query($SQL3);
$result3 = $statement3->fetch_assoc();
$result3 = $result3['RoleID'];

if($result3=='administrator') {
	$SQL4 = "SELECT * FROM events ORDER BY id";
	$result4 = $conn->query($SQL4);
	if ($result4->num_rows > 0) {
    while($row = $result4->fetch_assoc()) {

		 $data[] = array(
		  'id'   => $row["id"],
		  'title'   => $row["title"],
		  'start'   => $row["start_event"],
		  'end'   => $row["end_event"]
		 );
	}
	}	
}
else {

	$SQL = "SELECT DisciplineID FROM ums_user WHERE ID = '$ID'";
	$statement = $conn->query($SQL);
	$result = $statement->fetch_assoc();
	$result = $result['DisciplineID'];

	$SQL2 = "SELECT * FROM events WHERE discipline = '$result' OR discipline = '0' ORDER BY id";
	$statement2 = $conn->query($SQL2);

	if ($statement2->num_rows > 0) {
	    while($row = $statement2->fetch_assoc()) {

			$data[] = array(
			'id'   => $row["id"],
			'title'   => $row["title"],
			'start'   => $row["start_event"],
			'end'   => $row["end_event"]
			 );
		}
	}
}


/*send Events to the calendar UI*/
echo json_encode($data);

?>