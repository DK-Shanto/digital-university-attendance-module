<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_SCHOLARSHIP.'dao/class.catagory_dao.inc';


/*
	Catagory Process Object 
*/
Class CatagoryBAO{

	private $_DB;
	private $_CatagoryDAO;

	public function __construct(){

		$this->_CatagoryDAO = new CatagoryDAO();

	}

	//new Catagory post request funtion with the Catagory object
	public function newCatagoryRequest($Catagory){

		$Result = new Result();	
		$Result = $this->_CatagoryDAO->newCatagoryRequest($Catagory);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in CatagoryDAO.newCatagoryRequest()");		

		return $Result;
	}

	//get all catagory information
	public function getAllCatagorys(){

		$Result = new Result();	
		$Result = $this->_CatagoryDAO->getAllCatagorys();
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in CatagoryDAO.getAllCatagorys()");		

		return $Result;
	}

	//delete an existing catagory
	public function deleteCatagory($Catagory){

		$Result = new Result();	
		$Result = $this->_CatagoryDAO->deleteCatagory($Catagory);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in CatagoryDAO.deleteCatagory()");		

		return $Result;

	}


	//read an catagory object based on its id form catagory object
	public function readCatagory($Catagory){


		$Result = new Result();	
		$Result = $this->_CatagoryDAO->readCatagory($Catagory);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in CatagoryDAO.readCatagory()");		

		return $Result;


	}

	//update an catagory object based on its current information
	public function updateCatagory($Catagory){

		$Result = new Result();	
		$Result = $this->_CatagoryDAO->updateCatagory($Catagory);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in CatagoryDAO.updateCatagory()");		

		return $Result;
	}



}

?>