<?php
// write dao object for each class

include_once COMMON.'class.common.inc';
include_once UTILITY.'class.util.inc';
include_once COMMON.'class.common.book.inc';

Class BookDAO{
	private $_DB;
	private $_Book;

	public function __construct(){

		$this->_DB = DBUtil::getInstance();
		$this->_Book = new Book();
	}

	public function newBookRequest($Book){

		$UserName = $Book->getUserName();
		$Title=$Book->getTitle();
		$Edition=$Book->getEdition();
		$Writter=$Book->getWritter();
		$Description=$Book->getDescription();
		$UserID=$Book->getUserID();
		$Ammount = $Book->getAmmount();
		$ContactNumber=$Book->getContactNumber();
		$Date = new DateTime('now', new DateTimezone('Asia/Dhaka'));
		$dt = $Date->format('Y-m-j');
		$img_name=$Book->getImageName();
		$img=$Book->getImage();
		$Date= date("Y-m-d");
		$SQL = "INSERT INTO bsms_book(user_name,name,edition,writter,description,user_id,ammount,contact_number,date,img_name,img) VALUES('$UserName','$Title','$Edition','$Writter','$Description','$UserID','$Ammount','$ContactNumber','$dt','$img_name','$img')";
		//beginning a transaction
		$this->_DB->getConnection()->begin_transaction(MYSQLI_TRANS_START_READ_WRITE);
		//creating the Book
		$SQL = $this->_DB->doQuery($SQL);

		//closing the transaction
		$this->_DB->getConnection()->commit();

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject("New Book Request Submitted Successfully.");

		return $Result;
	}

}
?>
