<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_BOOK.'dao/class.book_post_dao.inc';


/*
	book Process Object
*/
Class BookBAO{

	private $_DB;
	private $_BookDAO;

	public function __construct(){

		$this->_BookDAO = new BookDAO();

	}

	//new Book post request funtion with the Book object
	public function newBookRequest($Book){

		$Result = new Result();
		$Result = $this->_BookDAO->newBookRequest($Book);

		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in BookDAO.newBookRequest()");

		return $Result;


	}

}

//$_Log->log(LogUtil::$DEBUG," exit the class.userbao.inc");

?>
