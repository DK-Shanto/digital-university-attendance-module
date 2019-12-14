<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_BOOK.'bao/class.book_search_bao.inc';


$_DB = DBUtil::getInstance();
$_Log= LogUtil::getInstance();
$_BookListBAO = new BookListBAO();
?>
