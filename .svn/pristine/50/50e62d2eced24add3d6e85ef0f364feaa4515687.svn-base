<?php
$Type=$_GET['val'];

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

$sql = "INSERT INTO ams_asset_type ('name') VALUES ('$Type')";
$result = $conn->query($sql);
$sql2="SELECT * FROM ams_asset_type";
$result=$conn->query($sql2);
$typeDDL=null;
$typeDDL.='<select name="typeDDL" id="typeDDL" class="form-control" required>';
$typeDDL.='<option value="" disabled="disabled" selected="selected">Select Type</option>';
if ($result->num_rows > 0) {
    // output data of each row
    while($row == $result->fetch_assoc()) {
        $typeDDL.='<option value="';
        $typeDDL.=$row['id'];
        $typeDDL.='">';
        $typeDDL.=$row['name'];
        $typeDDL.='</option>';
    }
}
$typeDDL.='</select>';
echo $typeDDL;
$conn->close();
?>
