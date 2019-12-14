<!--Email CRUD-->
<?php
include_once UTILITY.'class.util.inc';
include_once MODULES_EMAIL.'dao/class.emailRenewdao.inc';

/*
	User Business Object
*/
Class EmailRenewBao
{

    private $_EmailRenewDao;

    function __construct()
    {
        $this->_EmailRenewDao = new EmailRenewDao();
    }

    //get paginated emails
    public function getLimitEmail($page,$limit){
        $Result=$this->_EmailRenewDao->getLimitEmail($page,$limit);

        if(!$Result->getIsSuccess()){
            $Result->setResultObject("Database failure in EmailRenewDao.getLimitEmail($page,$limit)");
        }

        return $Result;
    }

    //get renew email
    public function getRenewEmail(){
        $Result=$this->_EmailRenewDao->getRenewEmail();

        if (!$Result->getIsSuccess()){
            $Result->setResultObject("Database failure in EmailRenewDao.getRenewEmail()");
        }

        return $Result;
    }
}