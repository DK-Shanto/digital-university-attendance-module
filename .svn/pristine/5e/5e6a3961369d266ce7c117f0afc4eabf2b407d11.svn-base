<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_SCHOLARSHIP.'dao/class.cocurricular_dao.inc';


/*
	Cocurricular Process Object 
*/
Class CocurricularBAO{

	private $_DB;
	private $_CocurricularDAO;

	public function __construct(){

		$this->_CocurricularDAO = new CocurricularDAO();

	}

	//new Cocurricular post request funtion with the Cocurricular object
	public function newCocurricularRequest($Cocurricular){

		$Result = new Result();	
		$Result = $this->_CocurricularDAO->newCocurricularRequest($Cocurricular);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in CocurricularDAO.newCocurricularRequest()");		

		return $Result;
	}

	//get all Cocurricular information
	public function getAllCocurriculars(){

		$Result = new Result();	
		$Result = $this->_CocurricularDAO->getAllCocurriculars();
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in CocurricularDAO.getAllCocurriculars()");		

		return $Result;
	}

	//delete an existing Cocurricular
	public function deleteCocurricular($Cocurricular){

		$Result = new Result();	
		$Result = $this->_CocurricularDAO->deleteCocurricular($Cocurricular);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in CocurricularDAO.deleteCocurricular()");		

		return $Result;

	}


	//read an Cocurricular object based on its id form Cocurricular object
	public function readCocurricular($Cocurricular){


		$Result = new Result();	
		$Result = $this->_CocurricularDAO->readCocurricular($Cocurricular);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in CocurricularDAO.readCocurricular()");		

		return $Result;


	}

	//update an Cocurricular object based on its current information
	public function updateCocurricular($Cocurricular){

		$Result = new Result();	
		$Result = $this->_CocurricularDAO->updateCocurricular($Cocurricular);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in CocurricularDAO.updateCocurricular()");		

		return $Result;
	}



}

?>