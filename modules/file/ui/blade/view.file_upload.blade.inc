<?php
include_once UTILITY.'class.util.inc';
include_once MODULES_FILE.'bao/class.filebao.inc';
include_once MODULES_FILE.'bao/class.file_assignbao.inc';
include_once MODULES_USER.'bao/class.disciplinebao.inc'; //module dependecy
include_once MODULES_USER.'bao/class.userbao.inc'; //module dependecy



$globalUser = $_SESSION['globalUser'];



$_FileBAO = new FileBAO();
$_DB = DBUtil::getInstance();
$_File_assignBAO = new File_assignBAO();

$_DisciplineBAO = new DisciplineBAO();
$_UserBAO = new UserBAO();

//$array = array("userId1", "userId2", "userId3");
//$discipline = array("CSE","ECE","MATH");

/* saving a new File account*/
if(isset($_POST['save']))
{
    //

    $uploadOk = 1;
    $target_dir = "uploads/file/";
    $target_file = $target_dir.basename($_FILES["fileToUpload"]["name"]);
    $id = hash_file('md5',$_FILES["fileToUpload"]["tmp_name"]);
    $discipline = $_POST["discipline"];
    $receiver = $_POST["users"];
    $link = $_FILES["fileToUpload"]["tmp_name"];

    if (file_exists($target_file)) {
        echo '<br>'. "Sorry, file already exists.";
        $uploadOk = 0;
    }
// // Check file size
// if ($_FILES["fileToUpload"]["size"] > 500000) {
//     echo "Sorry, your file is too large.";
//     $uploadOk = 0;
// }
// Allow certain file formats
// if($imageFileType != "jpg" && $imageFileType != "png" && $imageFileType != "jpeg"
// && $imageFileType != "gif" ) {
//     echo "Sorry, only JPG, JPEG, PNG & GIF files are allowed.";
//     $uploadOk = 0;
// }
// Check if $uploadOk is set to 0 by an error
    if ($uploadOk == 0) {
        echo '<br>'.'<strong style=" color:red; ">'."Sorry, your file was not uploaded.".'</strong>';
// if everything is ok, try to upload file
    } else {
        if (move_uploaded_file($_FILES["fileToUpload"]["tmp_name"], $target_file)) {
            echo '<br>'.'<strong style=" color:green; ">'."The file ". basename( $_FILES["fileToUpload"]["name"]). " has been uploaded.".'</strong>';

            //

            $File = new File();
            $File->setReceiver($receiver);
            $File->setID($id);
            $File->setCreator($globalUser->getID());
            $File->setName($_DB->secureInput($_POST['users']));
            //.$File->setLink($_DB->secureInput($_POST['link']));
            $File->setLink($target_file);
            $File->setDiscipline($_POST['discipline']);



            $FileAssign = new File_assign();
            $FileAssign->setID(Util::getGUID());
            $FileAssign->setFile($File->getID());
            $FileAssign->setFileComment($_DB->secureInput($_POST['Comment']));
            //$FileAssign->setCreationDate(date("y/m/d"));
            $FileAssign->setIsPending(1);
            $FileAssign->setHasSeen(0);
            $FileAssign->setIsRejected(0);
            $FileAssign->setIsApproved(0);
            $FileAssign->setPreviousUser($File->getCreator());
            $FileAssign->setCurrentUser($File->getName());
            $FileAssign->setCreationDate(date("Y-m-d H:i:s"));

            $_FileBAO->createFile($File);
            //$_File_assignBAO->createFile_assign($FileAssign);

            //


        } else {
            echo '<br>'.'<strong style=" color:red; ">'."Sorry, there was an error uploading your file.".'</strong>';
        }
    }

}


?>

