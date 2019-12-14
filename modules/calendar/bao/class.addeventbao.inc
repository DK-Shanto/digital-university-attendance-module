<?php

	include_once UTILITY.'class.util.inc';
	include_once MODULES_CALENDAR.'dao/class.addeventdao.inc';


/*
	User Business Object 
*/

class AddEventBAO {

	private $_DB;
	private $_AddEventDAO;

	public function __construct() {

	$this->_AddEventDAO = new AddEventDAO();

	}

//create event funtion with the event object
	public function AddEvent($Event){

		$Result = new Result();	
		$Result = $this->_AddEventDAO->AddEvent($Event);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in AddEventDAO.AddEvent()");		

		return $Result;

	}
	
}



?>