<?php
// write dao object for each class

include_once COMMON.'class.common.inc';
include_once UTILITY.'class.util.inc';
include_once COMMON.'class.common.book.inc';


Class BookListDAO{

	private $_DB;
	private $_Book;

	public function __construct(){

		$this->_DB = DBUtil::getInstance();
		$this->_Book = new Book();
	}

	// get all the users from the database using the database query
	public function getAllBook(){

		$BookList = array();

		$this->_DB->doQuery("SELECT * FROM bsms_book");

		$rows = $this->_DB->getAllRows();

		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];
			$this->_Book = new Book();

		    $this->_Book->setUserID ( $row['user_id']);
		    $this->_Book->setTitle ( $row['name'] );
		    $this->_Book->setEdition ( $row['edition'] );
		    $this->_Book->setWritter( $row['writter'] );
				$this->_Book->setDescription( $row['description'] );
		    $this->_Book->setAmmount( $row['ammount'] );
		    $this->_Book->setContactNumber( $row['contact_number'] );
		    $this->_Book->setDate( $row['date'] );
				$this->_Book->setImageName($row['img_name']);
				$this->_Book->setImage($row['img']);
			  //echo '<img src="data:image;base64,'.base64_encode($row['img']).' ">';
		    $BookList[]=$this->_Book;

		}


		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($BookList);

		return $Result;
	}
}

?>
