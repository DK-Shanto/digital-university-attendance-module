<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_BOOK.'dao/class.book_search_dao.inc';


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
}
?>
