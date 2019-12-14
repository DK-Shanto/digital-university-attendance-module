<!--Search and add members-->
<?php
$Key=$_GET['key'];
$PId=$_GET['pid'];

if (strlen($Key)>0) {
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

    $sql = "SELECT ums_user.Email FROM ums_user INNER JOIN ums_user_role ON ums_user.ID=ums_user_role.UserID
    INNER JOIN ums_role ON ums_user_role.RoleID=ums_role.ID WHERE ums_role.Name='Teacher'
    AND ums_user.Email NOT IN (SELECT tms_supervisor_thesis.supervisor_id FROM tms_supervisor_thesis WHERE 
    tms_supervisor_thesis.thesis_id='".$PId."') AND ums_user.Email LIKE '%$Key%'";

    $hint="";
    $result = $conn->query($sql);
    if ($result->num_rows > 0) {
        while ($res=$result->fetch_assoc()){
            if($hint==""){
                $hint='<a href="?id='.$PId.'&auid2='.$res['Email'].'" onclick="return confirm(\'sure to add !\');">'.$res['Email'].'</a>';

            }else{
                $hint=$hint.'<br /><a href="?id='.$PId.'&auid2='.$res['Email'].'" onclick="return confirm(\'sure to add !\');">'.$res['Email'].'</a>';

            }
        }
    }
    if($hint==""){
        echo "No Supervisor Found";
    }else{
        echo $hint;
    }

    $conn->close();
}
?>
