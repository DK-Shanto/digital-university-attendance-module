<?php
$Serial=$_GET['val'];

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

$sql = "SELECT * FROM ams_asset WHERE ams_asset.serialNo='".$Serial."'";
$res = $conn->query($sql);
$result=$res->fetch_array();
if (empty($result)){
    echo "";
}else{
    echo "Asset Already Exists";
}
$conn->close();
?>
