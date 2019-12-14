<?php

include_once UTILITY.'class.util.inc';

include_once MODULES_CCA.'dao/class.ccadao.inc';

/*
	School Business Object
*/
Class CCABAO{

	private $_DB;
	private $_CCADAO;

	 public function __construct(){

		$this->_CCADAO = new CCADAO();

	}

	//get all Schools value
	public function getAllCategory()
	{

		$Result = new Result();
		$Result = $this->_CCADAO->getAllCategory();

		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in CCADAO.getAllCategory()");

		return $Result;
	}
	public function getAllCCA()
	{

		$Result = new Result();
		$Result = $this->_CCADAO->getAllCCA();

		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in CCADAO.getAllCCA()");

		return $Result;
	}
	public function updatecat($User){

		$Result = new Result();
		$Result = $this->_CCADAO->updatecat($User);

		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in UserDAO.deleteUser()");

		return $Result;

	}
public function readcca($Role){


		$Result = new Result();
		$Result = $this->_CCADAO->readcca($Role);

		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in RoleDAO.readRole()");

		return $Result;


	}
//88888888888888888888888888

public function CCADELETE($User){

		$Result = new Result();
		$Result = $this->_CCADAO->CCADELETE($User);

		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in UserDAO.deleteUser()");

		return $Result;

	}




	public function getAllOrganizer()
	{

		$Result = new Result();
		$Result = $this->_CCADAO->getAllOrganizer();

		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in CCADAO.getAllOrganizer()");

		return $Result;
	}
	public function AddCatagory($ADDCAT)
	{

		$Result = new Result();
		$Result = $this->_CCADAO->AddCatagory($ADDCAT);

		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in CCADAO.getAllCategory()");

		return $Result;
	}

	public function SearchEvent($query)
	{
		$Result = new Result();
		$Result = $this->_CCADAO->SearchEvent($query);


	}

	public function findMyByDate($User,$date)
	{
		$Result = new Result();
		$Result = $this->$_CCADAO->findMyByDate($User,$date);

		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in CCADAO.getAllCCA())");		

		return $Result;
	}



}


?>
