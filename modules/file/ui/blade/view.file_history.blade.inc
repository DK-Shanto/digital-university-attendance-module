<?php
include_once UTILITY.'class.util.inc';
include_once MODULES_FILE.'bao/class.filebao.inc';
include_once MODULES_FILE.'bao/class.file_assignbao.inc';
include_once MODULES_USER.'bao/class.disciplinebao.inc'; //module dependecy
include_once MODULES_USER.'bao/class.userbao.inc'; //module dependecy



$globalUser = $_SESSION['globalUser'];
$_FileBAO = new FileBAO();
$_DB = DBUtil::getInstance();
$_File_assignBAO = new File_assignBAO();
$_DisciplineBAO = new DisciplineBAO();
$_UserBAO = new UserBAO();




?>