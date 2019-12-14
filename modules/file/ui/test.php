<?php

if ($_SERVER['REQUEST_METHOD'] == 'GET') {

    $fileID = $_GET['fileid'];
    $userId = $_GET['userId'];
    $conn = mysqli_connect("localhost", "root", "", "cseku2");



    $sql = "SELECT * 
FROM fms_fileassign,fms_file,ums_user,
							(SELECT ums_user.ID AS FileSender,ums_discipline.Name AS DispName
							FROM ums_discipline,ums_user
							WHERE ums_discipline.ID = ums_user.DisciplineID) AS T
WHERE fms_fileassign.ID = '$fileID' AND fms_file.CurrentUser = '$userId' AND fms_fileassign.sender = T.FileSender AND ums_user.ID = fms_fileassign.sender";




    $result=mysqli_query($conn,$sql);


    $rows = array();

    while($r = mysqli_fetch_assoc($result)) {
        $rows[] = $r;
    }
    echo(json_encode($rows));


    mysqli_close($conn);

}

?>