<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_VIDEO.'bao/class.videoCommentbao.inc';
include_once MODULES_VIDEO.'bao/class.videobao.inc';
$_VideoCommentBAO = new VideoCommentBAO();
$_DB = DBUtil::getInstance();

/* saving a new VideoComment account*/
if(isset($_POST['save']))
{
	 $VideoComment = new VideoComment();
	 $VideoComment->setVideoID($_GET['view']);
	 $VideoComment->setCommentID(Util::getGUID());
     $VideoComment->setComment($_DB->secureInput($_POST['txtComment']));
     $VideoComment->setCreatorID($_DB->secureInput($_SESSION["globalUser"]->getID ()));
     $VideoComment->setCommentIDTop('0');

	 $_VideoCommentBAO->createVideoComment($VideoComment);		 
}

if(isset($_POST['save2']))
{
	 $VideoComment = new VideoComment();
	 $VideoComment->setVideoID($_GET['view']);
	 $VideoComment->setCommentID(Util::getGUID());
     $VideoComment->setComment($_DB->secureInput($_POST['txtReply']));

     $VideoComment->setCreatorID($_DB->secureInput($_SESSION["globalUser"]->getID ()));
     $VideoComment->setCommentIDTop($_DB->secureInput($_POST['CommentID']));

	 $_VideoCommentBAO->createVideoComment($VideoComment);		 
}
if(isset($_POST['save3']))
{
	 $VideoComment = new VideoComment();
	 $VideoComment->setVideoID($_GET['view']);
	 $VideoComment->setCommentID(Util::getGUID());
     $VideoComment->setComment($_DB->secureInput($_POST['txtReply']));

     $VideoComment->setCreatorID($_DB->secureInput($_SESSION["globalUser"]->getID ()));
     $VideoComment->setCommentIDTop($_DB->secureInput($_POST['CommentID']));

	 $_VideoCommentBAO->createVideoComment($VideoComment);		 
}

/* deleting an existing VideoComment */
if(isset($_GET['del']))
{

	$VideoComment = new VideoComment();	
	$VideoComment->setCommentID($_GET['del']);	
	$_VideoCommentBAO->deleteVideoComment($VideoComment); //reading the VideoComment object from the result object

	header("Location:".PageUtil::$VIDEO_Comment);
}

/* reading an existing VideoComment information */
if(isset($_GET['edit']))
{
	$VideoComment = new VideoComment();	
	$VideoComment->setCommentID($_GET['edit']);	
	$getROW = $_VideoCommentBAO->readVideoComment($VideoComment)->getResultObject(); //reading the VideoComment object from the result object
}

/*updating an existing VideoComment information*/
if(isset($_POST['update']))
{
	$VideoComment = new VideoComment();	

    $VideoComment->setCommentID ($_GET['edit']);
    $VideoComment->setComment( $_POST['txtAns'] );
	
	$_VideoCommentBAO->updateVideoComment($VideoComment);

	header("Location:".PageUtil::$VIDEO_Comment);
}



////$_Log->log(LogUtil::$DEBUG," exit blade.videoComment.inc");

?>