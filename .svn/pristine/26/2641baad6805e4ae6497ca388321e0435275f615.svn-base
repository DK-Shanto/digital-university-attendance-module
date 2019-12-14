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
    $ext = pathinfo($target_file, PATHINFO_EXTENSION);

    $target_file_link = random_string(10).".".$ext;
    //$id = hash_file('md5',$_FILES["fileToUpload"]["tmp_name"]);

    $target_file_link = $target_dir.$target_file_link;



    echo $target_file_link;


    $id = Util::getGUID();
    $discipline = "";
    $receiver = $_POST["users"];
    $link = $_FILES["fileToUpload"]["tmp_name"];
    $comment = $_POST["Comment"];

    //move_uploaded_file($_FILES["fileToUpload"]["tmp_name"], $target_dir.$target_file_link);





    if (file_exists($target_file_link)) {
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
        if (move_uploaded_file($_FILES["fileToUpload"]["tmp_name"], $target_file_link)) {
            echo '<br>'.'<strong style=" color:green; ">'."The file ". basename( $_FILES["fileToUpload"]["name"]). " has been uploaded.".'</strong>';

            //



            $File = new File();
            $File->setID($id);
            $File->setCreator($globalUser->getID());
            $File->setLink($target_file_link);
            $File->setCurrentUser($receiver);




            $FileAssign = new File_assign();
            $FileAssign->setFile($File);
            $FileAssign->setFileComment($_DB->secureInput($_POST['Comment']));
            $FileAssign->setSender($globalUser->getID());
            $FileAssign->setReceiver($receiver);
            $FileAssign->setTimestamp("");
            $FileAssign->setLinks($target_file_link." ".$globalUser->getID()." ".time());

            $FileCreationResult = $_FileBAO->createFile($File);
            if ($FileCreationResult->getIsSuccess())
            {
                echo "File Done ";

                $FileAssignResult = $_File_assignBAO->createFile_assign($FileAssign);

                if ($FileAssignResult->getIsSuccess())
                {
                    header("Location:".PageUtil::$FILE);
                }
            }

            //$_File_assignBAO->createFile_assign($FileAssign);

            //


        } else {
            echo '<br>'.'<strong style=" color:red; ">'."Sorry, there was an error uploading your file.".'</strong>';
        }


    }



}

function random_string($length) {
    $key = '';
    $keys = array_merge(range(0, 9), range('a', 'z'));

    for ($i = 0; $i < $length; $i++) {
        $key .= $keys[array_rand($keys)];
    }

    return $key;

}





//echo '<br> log:: exit blade.share.inc';
//header("Location:".PageUtil::$FILE_STATUS);
?>


