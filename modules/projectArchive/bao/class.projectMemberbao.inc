<!--Assign or remove members form a project-->
<?php
include_once UTILITY.'class.util.inc';
include_once MODULES_PROJECT.'dao/class.projectMemberdao.inc';

class ProjectMemberBao{
    private $_MemberDao;

    public function __construct()
    {
        $this->_MemberDao=new ProjectMemberDao();
    }

    //add Member
    public function addMember($StudentProject){
        $Result=$this->_MemberDao->addMember($StudentProject);

        if(!$Result->getIsSuccess()){
            $Result->setResultObject("Database failure in MemberDao.addMember($StudentProject)");
        }
        return $Result;
    }

    //add Link
    public function addLink($LinkProject){
        $Result=$this->_MemberDao->addLink($LinkProject);

        if (!$Result->getIsSuccess()){
            $Result->setResultObject("Database failure in MemberDao.addLink($LinkProject)");
        }

        return $Result;
    }

    //get links of the project
    public function getLink($Project){
        $Result=$this->_MemberDao->getLink($Project);

        if(!$Result->getIsSuccess()){
            $Result->setResultObject("Database failure in MemberDao.getLink($Project)");
        }
        return $Result;
    }

    //get members of the project
    public function getMember($Project){
        $Result=$this->_MemberDao->getMember($Project);

        if(!$Result->getIsSuccess()){
            $Result->setResultObject("Database failure in MemberDao.getMember($Project)");
        }
        return $Result;
    }

    //get all students
    public function getStudent($Student){
        $Result=$this->_MemberDao->getStudent($Student);

        if(!$Result->getIsSuccess()){
            $Result->setResultObject("Database failure in MemberDao.getStudent($Student)");
        }
        return $Result;
    }

    //remove links from a project
    public function removeLink($Link){
        $Result=$this->_MemberDao->removeLink($Link);

        if(!$Result->getIsSuccess()){
            $Result->setResultObject("Database failure in MemberDao.removeLink($Link)");
        }
        return $Result;
    }

    //remove members from a project
    public function removeMember($Student){
        $Result=$this->_MemberDao->removeMember($Student);

        if(!$Result->getIsSuccess()){
            $Result->setResultObject("Database failure in MemberDao.removeMember($Student)");
        }
        return $Result;
    }
}
?>
