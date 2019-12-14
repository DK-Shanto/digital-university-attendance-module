<?php
include_once 'blade/view.projectHome.blade.inc';
include_once COMMON.'class.common.inc';
include_once COMMON.'class.paginate.inc';
?>

<div class="container">

    <!--Projects List-->
    <div class="row">
        <?php
        $results_per_page=12;

        $_Paginate=new Paginate();
        $ProjectList=$_Paginate->loadPaginatedData($_ProjectHomeBao->getLimitProject($_Paginate->paginationInitial(),$results_per_page));

        foreach ($ProjectList as $project){
            ?>
            <div class="col-lg-3 portfolio-item">
                <div class="card h-37">
                    <a href="<?php echo PageUtil::$PROJECT_MEMBER.'?id='.$project->getProjectId();?>" class="card-header">
                         <img class="card-img-top" height="100" width="100" src="<?php echo $project->getProjectThumbnail();?>" alt="Project"></a>
                       
                    <div class="card-body">
                        <h4 class="card-title">
                            <a href="<?php echo PageUtil::$PROJECT_MEMBER.'?id='.$project->getProjectId();?>"><?php echo $project->getProjectTitle();?></a>
                        </h4>
                        <p class="card-text"><?php
                            if(strlen($project->getProjectDescription())>80){
                                echo substr($project->getProjectDescription(),0,80).'...';
                            }
                            else{
                                echo $project->getProjectDescription();
                            }
                            ?></p>
                    </div>
                </div>
            </div>
            <?php
        }
        ?>
    </div>

    <!--Pagination-->
    <?php
    echo $_Paginate->paginate($results_per_page,PageUtil::$PROJECT_HOME,$_ProjectBao->getAllProjects());
    ?>
</div>