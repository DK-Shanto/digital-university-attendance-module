<?php
include_once UTILITY.'class.util.inc';
include_once MODULES_JOB.'bao/class.job_application_bao.inc';
include_once MODULES_JOB.'bao/class.job_list_bao.inc';

$_DB = DBUtil::getInstance();
$_Log= LogUtil::getInstance();
$_JobApplicationBAO = new JobApplicationBAO();
$_JobListBAO = new JobListBAO();

/* deleting an existing user */
if(isset($_GET['details']))
{

	$Job = new Job();	
	$Job->setID($_GET['details']);	
	$Job=$_JobListBAO->readJobPositions($Job)->getResultObject();//reading the user object from the result object
}

/* deleting an existing user */
if(isset($_GET['personcv']))
{
	$_SESSION['cvid'] = $_GET['personcv'];
	header("Location:".PageUtil::$JOB_CV_SHOW);
}

?>