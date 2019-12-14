<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_FILE.'bao/class.filebao.inc';
//include_once MODULES_FILE.'bao/class.sharebao.inc';
include_once MODULES_FILE.'bao/class.File_assignbao.inc';
include_once MODULES_USER.'bao/class.disciplinebao.inc'; //module dependency
include_once MODULES_USER.'bao/class.userbao.inc'; //module dependency




if(isset($_GET['action']) && !empty($_GET['action'])) {
    $action = $_GET['action'];
    echo $action;
}




//$fileVarible = $_SESSION['fileVarible'];
$globalUser = $_SESSION['globalUser'];
//$globalFileID = $_SESSION['globalFileID'];

$_FileBAO = new FileBAO();
$_DB = DBUtil::getInstance();
$_File_assignBAO = new File_assignBAO();

$_DisciplineBAO = new DisciplineBAO();
$_UserBAO = new UserBAO();

if(isset($_GET['edit']))
{
	$File = new File();
	$File->setID($_GET['edit']);
	$getROW = $_FileBAO->readFile($File)->getResultObject(); //reading the File object from the result object
}

/*
if(isset($_GET['history']))
{
	$_SESSION['globalFileID'] = $_GET['history'];
	header("Location:".PageUtil::$FILE_LOG);

	//reading the File object from the result object
}
*/
if(isset($_GET['send']))
{
	$File = new File_assign();
	$File->setID($_GET['send']);
	$getROW = $_File_assignBAO->readFile_assign($File)->getResultObject();

	$_SESSION['globalFileIDSend'] = $getROW;
	header("Location:".PageUtil::$FILE_SHARE);

	//reading the File object from the result object
}

if(isset($_GET['accept']))
{
	$FileAssign = new File_assign();

	$FileAssign->setID($_GET['accept']);

	$Result = $_File_assignBAO->readFile_assign($FileAssign);
	if($Result->getIsSuccess()){

		$FileList = $Result->getResultObject();
		$FileAssign = $FileList;

	}


	$FileAssign->setIsPending(0);
	$FileAssign->setHasSeen(1);
	$FileAssign->setIsRejected(0);
	$FileAssign->setIsApproved(1);
	$FileAssign->setApproveDate(date("y/m/d"));


	$_File_assignBAO->updateFile_assign($FileAssign);

	header("Location:".PageUtil::$FILE_NOTIFY);

}

if(isset($_GET['reject']))
{
	$FileAssign = new File_assign();

	$FileAssign->setID($_GET['reject']);

	$Result = $_File_assignBAO->readFile_assign($FileAssign);
	if($Result->getIsSuccess()){

		$FileList = $Result->getResultObject();
		$FileAssign = $FileList;

	}


	$FileAssign->setIsPending(0);
	$FileAssign->setHasSeen(1);
	$FileAssign->setIsRejected(1);
	$FileAssign->setIsApproved(0);
	$FileAssign->setApproveDate(date("y/m/d"));


	$_File_assignBAO->updateFile_assign($FileAssign);

	header("Location:".PageUtil::$FILE_NOTIFY);

}

//echo '<br> log:: exit notification.blade.file.inc';

if (isset($_POST['forward']))
{

    $links = $_POST['fileIdLinks'];
    $receiver = $_POST['users'];
    $fileId = $_POST['fileId'];
    $uploadOk = 1;
    $target_dir = "uploads/file/";


    $target_file = $target_dir.basename($_FILES["fileToUpload"]["name"]);

    $append = basename($_FILES["fileToUpload"]["name"]);



    $ext = pathinfo($target_file, PATHINFO_EXTENSION);
    $target_file_link = random_string(10).".".$ext;
    //$id = hash_file('md5',$_FILES["fileToUpload"]["tmp_name"]);
    $target_file_link = $target_dir.$target_file_link;





    if ($fileId == 'nothing')
    {
        //echo ("Select Any File ");
        echo ("<h4 style='color: red'>Select Any File </h4>");
    }

    else {

        if (!$append)
        {
            $File = new File();
            $File->setID($fileId);
            $File->setCurrentUser($receiver);

            $FileAssign = new File_assign();
            $FileAssign->setFile($File);
            $FileAssign->setFileComment($_DB->secureInput($_POST['Comment']));
            $FileAssign->setSender($globalUser->getID());
            $FileAssign->setReceiver($receiver);
            $FileAssign->setTimestamp("");
            $FileAssign->setLinks($links);


            $FileCurrentUserUpdateResult = $_FileBAO->updateCurrentUser($File);
            if ($FileCurrentUserUpdateResult->getIsSuccess()) {
                $FileAssignResult = $_File_assignBAO->createFile_assign($FileAssign);

                if ($FileAssignResult->getIsSuccess()) {
                    header("Location:".PageUtil::$FILE);

                }
            }

        }



        else
        {
            if (file_exists($target_file_link)) {
                echo '<br>'. "Sorry, file already exists.";
                $uploadOk = 0;
            }


            if ($uploadOk == 0) {
                echo '<br>'.'<strong style=" color:red; ">'."Sorry, your file was not uploaded.".'</strong>';
// if everything is ok, try to upload file
            }

            else {
                if (move_uploaded_file($_FILES["fileToUpload"]["tmp_name"], $target_file_link)) {
                    echo '<br>'.'<strong style=" color:green; ">'."The file ". basename( $_FILES["fileToUpload"]["name"]). " has been uploaded.".'</strong>';

                    //

                    echo "check db";






                    $File = new File();
                    $File->setID($fileId);
                    $File->setLink($target_file_link);
                    $File->setCurrentUser($receiver);




                    $FileAssign = new File_assign();
                    $FileAssign->setFile($File);
                    $FileAssign->setFileComment($_DB->secureInput($_POST['Comment']));
                    $FileAssign->setSender($globalUser->getID());
                    $FileAssign->setReceiver($receiver);
                    $FileAssign->setTimestamp("");
                    //$FileAssign->setLinks($target_file_link);







                    $FileLinkUpdateResult = $_FileBAO->updateFileLink($File);
                    if ($FileLinkUpdateResult->getIsSuccess())
                    {

                        echo "File DOne ";

                        $Result = $_File_assignBAO->getFileAssignToBeAppended($File);
                        $FileAssignToBeAppendedList = $Result->getResultObject();


                            $FileAssignToBeAppended = $FileAssignToBeAppendedList[0];
                            $previous_links =  $FileAssignToBeAppended->getLinks();

                            $FileAssign->setLinks($previous_links.",".$target_file_link." ".$globalUser->getID()." ".time());

                            echo ($FileAssign->getLinks());


                            $FileAssignResult = $_File_assignBAO->createFile_assign($FileAssign);


                        if ($FileAssignResult->getIsSuccess()) {
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




        //echo $fileId;



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

?>
