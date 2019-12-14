<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_BOOK.'dao/class.book_own_list_dao.inc';


/*
	User Business Object
*/
Class BookListBAO{

	private $_DB;
	private $_BookListDAO;

	public function __construct(){

		$this->_BookListDAO = new BookListDAO();

	}

	//get all users value
	public function getAllBook(){

		$Result = new Result();
		$Result = $this->_BookListDAO->getAllBook();

		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in BookListDAO.getAllBook()");

		return $Result;
	}
	public function readBookPositions($Book){


		$Result = new Result();
		$Result = $this->_BookListDAO->readBookPositions($Book);

		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in UserDAO.readUserRolesPositions()");

		return $Result;
	}

	public function updateBookRequest($Book){

		$Result = new Result();
		$Result = $this->_BookListDAO->updateBookRequest($Book);

		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in UserDAO.updateUser()");

		return $Result;
	}

	public function deleteBook($Book){


		$Result = new Result();
		$Result = $this->_BookListDAO->deleteBook($Book);

		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in UserDAO.readUserRolesPositions()");

		return $Result;
	}

}
?>
