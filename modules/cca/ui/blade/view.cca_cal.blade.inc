<?php
include_once MODULES_CCA.'bao/class.ccauserbao.inc';
include_once MODULES_CCA.'bao/class.ccabao.inc';
include_once MODULES_USER.'bao/class.userbao.inc';
include_once MODULES_USER.'bao/class.rolebao.inc';
include_once MODULES_USER.'bao/class.positionbao.inc';

	$_DB = DBUtil::getInstance();
	$_Log= LogUtil::getInstance();
	//$_Task = new Task();
	$_UserBAO = new UserBAO();
	//$_TaskBAO = new TaskBAO();

	$globalUser = $_SESSION["globalUser"];

	$userPositions = $_UserBAO->readUserRolesPositions($globalUser)->getResultObject(); //reading the user
	$userDetails = $_UserBAO->readUserDetails($globalUser)->getResultObject();
	$ID = $userPositions->getID();
	$User = new User();
	$User->setID($ID);
	$result;
		if(isset($_GET['day']))
		 {
	        $day=$_GET['day'];
		 }
		 else
		 {
		    $day=date("j");
		 }
		 if(isset($_GET['month']))
		 {
	        $month=$_GET['month'];
		 }
		 else
		 {
		    $month=date("n");
		 }
		 if(isset($_GET['year']))
		 {
	        $year=$_GET['year'];
		 }
		 else
		 {
		    $year=date("Y");
		 }

			//calender variable
			$currentTimeStamp=strtotime("$year-$month-$day");
			$monthName=date("F",$currentTimeStamp);
			$numDays=date("t",$currentTimeStamp);
			$counter=0;

			$date1 = strtotime("$year-$month-1");
			$date2 = strtotime("$year-$month-$numDays");
			$date1 = date('Y-m-d',$date1);
			$date2 = date('Y-m-d',$date2);

			




?>
