<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_CCA.'dao/class.ccamenudao.inc';

/*
	School Business Object
*/
Class CCAMENUBAO{

	private $_DB;
	private $_CCAMENUDAO;

	public function __construct(){

		$this->_CCAMENUDAO = new CCAMENUDAO();

	}

	public function CATDELETE($User){

		$Result = new Result();
		$Result = $this->_CCAMENUDAO->CATDELETE($User);

		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in UserDAO.deleteUser()");

		return $Result;

	}
	public function updatecategory($User){

		$Result = new Result();
		$Result = $this->_CCAMENUDAO->updatecategory($User);

		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in UserDAO.deleteUser()");

		return $Result;

	}
	public function readCAT($Role){


		$Result = new Result();
		$Result = $this->_CCAMENUDAO->readCAT($Role);

		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in RoleDAO.readRole()");

		return $Result;


	}
public function getCATA()
	{

		$Result = new Result();
		$Result = $this->_CCAMENUDAO->getCATA();

		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in CCADAO.getAllCCA()");

		return $Result;
	}
	//get all Schools value
	public function getAllCategory()
	{

		$Result = new Result();
		$Result = $this->_CCAMENUDAO->getAllCategory();

		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in CCAMENUDAO.getAllCategory()");

		return $Result;
	}

	public function AddmenuCatagory($ADDCAT)
	{

		$Result = new Result();
		$Result = $this->_CCAMENUDAO->AddmenuCatagory($ADDCAT);

		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in CCAMENUDAO.getAllCategory()");

		return $Result;
	}






}


?>
