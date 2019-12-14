<!--Thesis Homepage-->
<?php
include_once UTILITY.'class.util.inc';
include_once MODULES_THESIS.'dao/class.thesisdao.inc';
include_once MODULES_THESIS.'dao/class.thesisHomedao.inc';

class ThesisHomeBao{

    private $_ThesisHomeDao;

    public function __construct()
    {
        $this->_ThesisHomeDao=new ThesisHomeDao();
    }

    //get paginated thesis
    public function getLimitThesis($page,$limit){
        $Result=$this->_ThesisHomeDao->getLimitThesis($page,$limit);

        if(!$Result->getIsSuccess()){
            $Result->setResultObject("Database failure in ThesisHomeDao.getLimitThesis($page,$limit)");
        }

        return $Result;
    }
}
?>
