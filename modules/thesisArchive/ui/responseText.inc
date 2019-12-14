<?php
$ID = $_GET["ID"];

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

$sql = "SELECT reg_course.Title FROM reg_course WHERE reg_course.ID='".$ID."'";
$result = $conn->query($sql);

if ($result->num_rows > 0) {
    $res=$result->fetch_array();
    echo $res['Title'];
} else {
    echo "No Course Selected";
}
$conn->close();
?>
