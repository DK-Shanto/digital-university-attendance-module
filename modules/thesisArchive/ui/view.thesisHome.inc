<?php

include_once COMMON.'class.common.inc';
include_once COMMON.'class.paginate.inc';
include_once 'blade/view.thesisHome.blade.inc';
?>

<div class="container">

    <!--Thesis List-->
    <div class="row">
        <?php
        $results_per_page=4;
        $_Paginate=new Paginate();
        $ThesisList=$_Paginate->loadPaginatedData($_ThesisHomeBao->getLimitThesis($_Paginate->paginationInitial(),$results_per_page));

        foreach ($ThesisList as $thesis){
            ?>
            <div class="col-lg-3 portfolio-item">
                <div class="card h-37">
                    <a href="<?php echo PageUtil::$THESIS_MEMBER.'?id='.$thesis->getThesisId();?>" class="card-header">
                        <img class="card-img-top" height = "100" weight = "100" src="<?php echo $thesis->getThesisThumbnail();?>"  alt="Thesis" ></a>
                    <div class="card-body">
                        <h4 class="card-title">
                            <a href="<?php echo PageUtil::$THESIS_MEMBER.'?id='.$thesis->getThesisId();?>"><?php echo $thesis->getThesisTitle();?></a>
                        </h4>
                        <p class="card-text"><?php
                            if(strlen($thesis->getThesisDescription())>80){
                                echo substr($thesis->getThesisDescription(),0,80).'...';
                            }
                            else{
                                echo $thesis->getThesisDescription();
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
    echo $_Paginate->paginate($results_per_page,PageUtil::$THESIS_HOME,$_ThesisBao->getAllThesis());
    ?>

</div>
