<?php
include_once UTILITY.'class.util.inc';
include_once MODULES_THESIS.'bao/class.thesisbao.inc';
include_once MODULES_THESIS.'bao/class.thesisHomebao.inc';

$_ThesisBao=new ThesisBao();
$_ThesisHomeBao=new ThesisHomeBao();
$_DB=DBUtil::getInstance();

?>
