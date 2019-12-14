<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_JOB.'bao/class.job_cv_show_bao.inc';

$_DB = DBUtil::getInstance();
$_Log= LogUtil::getInstance();
$_JobCVShowBAO = new JobCVShowBAO();

?>