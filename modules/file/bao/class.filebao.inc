<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_FILE.'dao/class.filedao.inc';


/*
	File Business Object
*/


Class FileBAO{

	private $_DB;
	private $_FileDAO;

	public function __construct(){

		$this->_FileDAO = new FileDAO();

	}

	//get all Files value
	public function getAllFiles(){

		$Result = new Result();
		$Result = $this->_FileDAO->getAllFiles();

		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in FileDAO.getAllFiles()");

		return $Result;
	}


	public function getAllReceivedFiles()
	{
		$Result = new Result();
		$Result = $this->_FileDAO->getAllReceivedFiles();

		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in FileDAO.getAllReceivedFiles()");

		return $Result;
	}

	//create File funtion with the File object
	public function createFile($File){

		$Result = new Result();
		$Result = $this->_FileDAO->createFile2($File);

		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in FileDAO.createFile()");

		return $Result;


	}

	public function updateFileLink($File)
	{
        $Result = new Result();
        $Result = $this->_FileDAO->updateFileLink($File);

        if(!$Result->getIsSuccess())
            $Result->setResultObject("Database failure in FileDAO.createFile()");

        return $Result;
	}


	public function updateCurrentUser($File)
	{
        $Result = new Result();
        $Result = $this->_FileDAO->updateCurrentUser($File);

        if(!$Result->getIsSuccess())
            $Result->setResultObject("Database failure in FileDAO.createFile()");

        return $Result;
	}

	//read an File object based on its id form File object
	public function readFile($File){


		$Result = new Result();
		$Result = $this->_FileDAO->readFile($File);

		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in FileDAO.readFile()");

		return $Result;


	}

	//update an File object based on its current information
	public function updateFile($File){

		$Result = new Result();
		$Result = $this->_FileDAO->updateFile($File);

		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in FileDAO.updateFile()");

		return $Result;
	}

	//delete an existing File
	public function deleteFile($File){

		$Result = new Result();
		$Result = $this->_FileDAO->deleteFile($File);

		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in FileDAO.deleteFIle()");

		return $Result;

	}

}

//echo '<br> log:: exit the class.filebao.inc';

?>
