<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_CCA.'dao/class.ccaorganizerdao.inc';

/*
	School Business Object
*/
Class CCAORGANIZERBAO{

	private $_DB;
	private $_CCAORGDAO;

	public function __construct(){

		$this->_CCAORGDAO = new CCAORGANIZERDAO();

	}

	//get all Schools value

	public function getAllOrganizer()
	{

		$Result = new Result();
		$Result = $this->_CCAORGDAO->getAllOrganizer();

		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in CCAMENUDAO.getAllOrganizer()");

		return $Result;
	}

	public function AddOrganizer($ADDORG)
	{

		$Result = new Result();
		$Result = $this->_CCAORGDAO->AddOrganizer($ADDORG);

		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in CCAMENUDAO.getAllOrganizer()");

		return $Result;
	}

	public function ORGDELETE($User){

		$Result = new Result();
		$Result = $this->_CCAORGDAO->ORGDELETE($User);

		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in UserDAO.deleteUser()");

		return $Result;

	}
	public function readORG($Role){


		$Result = new Result();
		$Result = $this->_CCAORGDAO->readORG($Role);

		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in RoleDAO.readRole()");

		return $Result;


	}
	public function updateorganizer($User){

		$Result = new Result();
		$Result = $this->_CCAORGDAO->updateorganizer($User);

		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in UserDAO.deleteUser()");

		return $Result;

	}
	public function getORG()
	{

		$Result = new Result();
		$Result = $this->_CCAORGDAO->getORG();

		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in CCADAO.getAllCCA()");

		return $Result;
	}





}


?>
