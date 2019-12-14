<?php


include_once UTILITY.'class.util.inc';
include_once MODULES_CALENDAR.'bao/class.addeventbao.inc';


//here comes module dependency
$_AddEventBAO = new AddEventBAO();

$_DB = DBUtil::getInstance();
$_Log= LogUtil::getInstance();


/* saving a new user account*/
if(isset($_POST['request']))
{
	$AddEvent = new AddEvent();	

	$AddEvent->setEventTitle(strtolower($_DB->secureInput($_POST['eventName']))); 
	/*$AddEvent->setEventDate($_DB->secureInput($_POST['eventDate']));*/
    $AddEvent->seteventStartTime($_DB->secureInput($_POST['eventStartTime']));
    $AddEvent->seteventEndTime($_DB->secureInput($_POST['eventEndTime'])); 
	$AddEvent->setDiscipline(strtolower($_DB->secureInput($_POST['selectDiscipline']))); 

	

	$Result = $_AddEventBAO->AddEvent($AddEvent);		

	if($Result->getIsSuccess()){
	   Util::printToast($Result->getResultObject());	
	}


}
?>