<?php
	
include_once COMMON.'class.common.inc';
include_once UTILITY.'class.util.inc';


Class AddEventDAO {

	private $_DB;


	public function __construct(){

		$this->_DB = DBUtil::getInstance();
	}


	//create user funtion with the user object
	public function AddEvent($Event){

		$EventTitle=$Event->getEventTitle();
		/*$EventDate=$Event->getEventDate();*/
		$eventStartTime=$Event->geteventStartTime();
		$eventEndTime=$Event->geteventEndTime();
		$Discipline=$Event->getDiscipline();
		
		$SQL = "INSERT INTO events(title,start_event,end_event,discipline) 
		 	VALUES('$EventTitle','$eventStartTime','$eventEndTime','$Discipline')";


		$SQL=$this->_DB->doQuery($SQL); 	

		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;	

	}
}
?>