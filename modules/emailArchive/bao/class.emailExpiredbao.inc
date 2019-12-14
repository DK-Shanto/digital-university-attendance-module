<!--Email CRUD-->
<?php
include_once UTILITY.'class.util.inc';
include_once MODULES_EMAIL.'dao/class.emailExpireddao.inc';

/*
	User Business Object
*/
Class EmailExpiredBao
{

    private $_EmailExpiredDao;

    function __construct()
    {
        $this->_EmailExpiredDao = new EmailExpiredDao();
    }

    //get paginated emails
    public function getLimitEmail($page,$limit){
        $Result=$this->_EmailExpiredDao->getLimitEmail($page,$limit);

        if(!$Result->getIsSuccess()){
            $Result->setResultObject("Database failure in EmailExpiredDao.getLimitEmail($page,$limit)");
        }

        return $Result;
    }

    //get renew email
    public function getExpiredEmail(){
        $Result=$this->_EmailExpiredDao->getExpiredEmail();

        if (!$Result->getIsSuccess()){
            $Result->setResultObject("Database failure in EmailExpiredDao.getExpiredEmail()");
        }

        return $Result;
    }
}