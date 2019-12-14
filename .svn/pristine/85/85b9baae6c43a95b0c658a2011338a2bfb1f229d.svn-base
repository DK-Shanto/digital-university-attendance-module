<?php
include_once 'blade/view.searchProject.blade.inc';
include_once COMMON.'class.common.inc';
?>

<link rel="stylesheet" href="./resources/css/sidebarStyle.css">

<div class="container">

    <!--Sidebar-->
    <div class="col-md-3">
      <nav class="navbar navbar-default sidebar" role="navigation">
        <div class="container-fluid">
            <div class="navbar-header mySideNav">
                <span><strong style="font-size: large">Filter</strong></span>
                <!--Responsive-->
                <button type="button" class="navbar-toggle" data-toggle="collapse" data-target="#bs-sidebar-navbar-collapse-1">
                    <span class="sr-only">Toggle navigation</span>
                    <span class="icon-bar"></span>
                    <span class="icon-bar"></span>
                    <span class="icon-bar"></span>
                </button>
            </div>
            <div class="collapse navbar-collapse" id="bs-sidebar-navbar-collapse-1">

                    <br><br>
                <!--Title-->
                <ul class="nav navbar-nav">
                    <li class="mySideNavList" >&nbsp Title<span class="pull-right"><input type="checkbox" name="cbtitle" id="cbtitle"<?php
                            if (isset($_POST['search'])&&isset($_POST['title'])&&!empty($_POST['title'])){
                                ?>
                                checked="checked"
                                <?php
                            }
                            ?> onchange="cbFunction();"></span></li><br>
                            

                    <!--Language-->
                    <li class="mySideNavList" > &nbsp Language &nbsp<span class="pull-right"><input type="checkbox" name="cblanguage" id="cblanguage"<?php
                            if (isset($_POST['search'])&&isset($_POST['language'])&&!empty($_POST['language'])){
                                ?>
                                checked="checked"
                                <?php
                            }
                            ?> onchange="cbFunction();"></span></li><br>

                    <!--Year-->
                    <li class="mySideNavList" >&nbsp Year &nbsp<span class="pull-right"><input type="checkbox" name="cbyear" id="cbyear"<?php
                            if (isset($_POST['search'])&&isset($_POST['year_id'])&&!empty($_POST['year_id'])){
                                ?>
                                checked="checked"
                                <?php
                            }
                            ?> onchange="cbFunction();"></span></li><br>

                    <!--Term-->
                    <li class="mySideNavList" >&nbsp Term &nbsp<span class="pull-right"><input type="checkbox" name="cbterm" id="cbterm"<?php
                            if (isset($_POST['search'])&&isset($_POST['term_id'])&&!empty($_POST['term_id'])){
                                ?>
                                checked="checked"
                                <?php
                            }
                            ?> onchange="cbFunction();"></span></li><br>

                    <!--Course-->
                    <li class="mySideNavList" >&nbsp Course &nbsp<span class="pull-right"><input type="checkbox" name="cbcourse" id="cbcourse"<?php
                            if (isset($_POST['search'])&&isset($_POST['course_id'])&&!empty($_POST['course_id'])){
                                ?>
                                checked="checked"
                                <?php
                            }
                            ?> onchange="cbFunction();"></span></li><br>

                    <!--Discipline-->
                    <li class="mySideNavList" >&nbsp Discipline &nbsp<span class="pull-right"><input type="checkbox" name="cbdiscipline" id="cbdiscipline"<?php
                            if (isset($_POST['search'])&&isset($_POST['discipline_id'])&&!empty($_POST['discipline_id'])){
                                ?>
                                checked="checked"
                                <?php
                            }
                            ?> onchange="cbFunction();"></span></li><br>

                    <!--Teacher-->
                    <li class="mySideNavList" >&nbsp Teacher &nbsp<span class="pull-right"><input type="checkbox" name="cbteacher" id="cbteacher"<?php
                            if (isset($_POST['search'])&&isset($_POST['teacher_id'])&&!empty($_POST['teacher_id'])){
                                ?>
                                checked="checked"
                                <?php
                            }
                            ?> onchange="cbFunction();"></span></li><br>

                  

                    <!--CreatedAt-->
                    <li class="mySideNavList" >&nbsp Date &nbsp<span class="pull-right"><input type="checkbox" name="cbdate" id="cbdate"<?php
                            if (isset($_POST['search'])&&isset($_POST['created_at'])&&!empty($_POST['created_at'])){
                                ?>
                                checked="checked"
                                <?php
                            }
                            ?> onchange="cbFunction();"></span></li><br>
                </ul>
            </div>
        </div>
    </nav>
    </div>

    <!--Search Div-->
    <div class="col-md-9">
        <div class="panel panel-default myPanel">

            <div class="panel-heading myHeading">
                <strong>&nbsp;Search Project</strong>
            </div>

            <div class="panel-body form-horizontal">

                <!--Search Form-->
                <form method="post" class="form-horizontal">

                    <!--Title-->
                    <div id="divtitle" class="form-group"  hidden >
                        <label for="title" class="control-label col-md-3">Title :</label>
                        <div class="col-md-7">
                            <input type="text" name="title" id="title" class="form-control" placeholder="Project Title" value="<?php
                            if (isset($_POST['search'])&&!empty($_POST['title'])) echo $_POST['title'];
                            ?>" required>
                        </div>
                    </div>

                    <!--Language-->
                    <div id="divlanguage" class="form-group"  hidden >
                        <label for="language" class="control-label col-md-3">Language :</label>
                        <div class="col-md-7">
                            <select name="language" id="language" class="form-control" required>
                                <option value="" selected="selected" disabled>Select Language</option>
                                <?php
                                $Result=$_SearchProjectBao->getAllLanguages();
                                if ($Result->getIsSuccess()){
                                    $LanguageList=$Result->getResultObject();
                                    foreach ($LanguageList as $language) {
                                        ?>
                                        <option value="<?php echo $language->getProjectLanguage();?>"<?php
                                        if (isset($_POST['search'])&&!empty($_POST['language'])&&$language->getProjectLanguage()==$_POST['language']) echo 'selected="selected"';
                                        ?>><?php echo $language->getProjectLanguage();?></option>
                                        <?php
                                    }
                                }else{
                                    echo $Result->getResultObject();
                                }
                                ?>
                            </select>
                        </div>
                    </div>

                    <!--Year-->
                    <div id="divyear" class="form-group"  hidden >
                        <label for="year_id" class="control-label col-md-3">Year :</label>
                        <div class="col-md-7">
                            <select name="year_id" id="year_id" class="form-control" required>
                                <option value="" selected="selected" disabled>Select Year</option>
                                <?php
                                $Result=$_ProjectBao->getAllYears();
                                if ($Result->getIsSuccess()){
                                    $YearList=$Result->getResultObject();
                                    foreach ($YearList as $year) {
                                        ?>
                                        <option value="<?php echo $year->getID();?>"<?php
                                        if (isset($_POST['search'])&&!empty($_POST['year_id'])&&$year->getID()==$_POST['year_id']) echo 'selected="selected"';
                                        ?>><?php echo $year->getName();?></option>
                                        <?php
                                    }
                                }else{
                                    echo $Result->getResultObject();
                                }

                                ?>
                            </select>
                        </div>
                    </div>

                    <!--Term-->
                    <div id="divterm" class="form-group"  hidden >
                        <label for="term_id" class="control-label col-md-3">Term :</label>
                        <div class="col-md-7">
                            <select name="term_id" id="term_id" class="form-control" required>
                                <option value="" selected="selected" disabled>Select Term</option>
                                <?php
                                $Result=$_ProjectBao->getAllTerms();
                                if ($Result->getIsSuccess()){
                                    $TermList=$Result->getResultObject();
                                    foreach ($TermList as $term) {
                                        ?>
                                        <option value="<?php echo $term->getID();?>"<?php
                                        if (isset($_POST['search'])&&!empty($_POST['term_id'])&&$term->getID()==$_POST['term_id']) echo 'selected="selected"';
                                        ?>><?php echo $term->getName();?></option>
                                        <?php
                                    }
                                }else{
                                    echo $Result->getResultObject();
                                }
                                ?>
                            </select>
                        </div>
                    </div>

                    <!--Course-->
                    <div id="divcourse" class="form-group"  hidden >
                        <label for="course_id" class="control-label col-md-3">Course :</label>
                        <div class="col-md-7">
                            <select name="course_id" id="course_id" class="form-control" required>
                                <option value="" selected="selected" disabled>Select Course</option>
                                <?php
                                $Result=$_ProjectBao->getAllCourses();
                                if ($Result->getIsSuccess()){
                                    $CourseList=$Result->getResultObject();
                                    foreach ($CourseList as $course) {
                                        ?>
                                        <option value="<?php echo $course->getID();?>"<?php
                                        if (isset($_POST['search'])&&!empty($_POST['course_id'])&&$course->getID()==$_POST['course_id']) echo 'selected="selected"';
                                        ?>><?php echo $course->getTitle();?></option>
                                        <?php
                                    }
                                }else{
                                    echo $Result->getResultObject();
                                }
                                ?>
                            </select>
                        </div>
                    </div>

                    <!--Discipline-->
                    <div id="divdiscipline" class="form-group"  hidden >
                        <label for="discipline_id" class="control-label col-md-3">Discipline :</label>
                        <div class="col-md-7">
                            <select name="discipline_id" id="discipline_id" class="form-control" required>
                                <option value="" selected="selected" disabled>Select Discipline</option>
                                <?php
                                $Result=$_ProjectBao->getAllDisciplines();
                                if ($Result->getIsSuccess()){
                                    $DisciplineList=$Result->getResultObject();
                                    foreach ($DisciplineList as $discipline) {
                                        ?>
                                        <option value="<?php echo $discipline->getID();?>"<?php
                                        if (isset($_POST['search'])&&!empty($_POST['discipline_id'])&&$discipline->getID()==$_POST['discipline_id']) echo 'selected="selected"';
                                        ?>><?php echo $discipline->getName();?></option>
                                        <?php
                                    }
                                }else{
                                    echo $Result->getResultObject();
                                }
                                ?>
                            </select>
                        </div>
                    </div>

                    <!--Teacher-->
                    <div id="divteacher" class="form-group"  hidden >
                        <label for="teacher_id" class="control-label col-md-3">Teacher:</label>
                        <div class="col-md-7">
                            <select name="teacher_id" id="teacher_id" class="form-control" required>
                                <option value="" selected="selected" disabled>Select Teacher</option>
                                <?php
                                $Result=$_ProjectBao->getAllTeachers();
                                if ($Result->getIsSuccess()){
                                    $TeacherList=$Result->getResultObject();
                                    foreach ($TeacherList as $teacher) {
                                        ?>
                                        <option value="<?php echo $teacher->getID();?>"<?php
                                        if (isset($_POST['search'])&&!empty($_POST['teacher_id'])&&$teacher->getID()==$_POST['teacher_id']) echo 'selected="selected"';
                                        ?>><?php echo $teacher->getFirstName().' '.$teacher->getLastName();?></option>
                                        <?php
                                    }
                                }else{
                                    echo $Result->getResultObject();
                                }
                                ?>
                            </select>
                        </div>
                    </div>
                
               
   

                    <!--CreatedAt-->
                    <div id="divcreated_at" class="form-group"  hidden >
                        <label for="created_at" class="control-label col-md-3">Date :</label>
                        <div class="col-md-7">
                            <input type="date" name="created_at" id="created_at" class="form-control" value="<?php
                            if (isset($_POST['search'])&&!empty($_POST['created_at'])) echo $_POST['created_at'];
                            ?>" required>
                        </div>
                    </div>

                    <br>

                    <!--Search Button-->
                    <div class="form-group">
                        <input type="submit" name="search" id="search" class="btn btn-primary col-md-2 col-md-offset-5" value="Search">
                    </div>
                </form>

            </div>
        </div>
    </div>
</div>

<!--Display Search Results-->
<?php
if (isset($_POST['search'])&&(!empty($_POST['title'])||!empty($_POST['language'])||!empty($_POST['year_id'])||!empty($_POST['term_id'])
    ||!empty($_POST['course_id'])||!empty($_POST['discipline_id'])||!empty($_POST['teacher_id'])||!empty($_POST['member_id'])||!empty($_POST['created_at']))){
    ?>
    <div class="col-md-12">
        <hr>
    </div>
    <div class="col-md-12">
    <div class="panel panel-table">
        <table class="table table-striped table-bordered table-responsive">
            <!--Header Row-->
            <tr>
                <th>Title</th>
                <th>Description</th>
                <th>Language</th>
                <th>Year</th>
                <th>Term</th>
                <th>Course</th>
                <th>Discipline</th>
                <th>Teacher</th>
                <th>Created At</th>
                <th>Updated At</th>
            </tr>

            <!--Table Cells-->
            <?php
            $Result=$_SearchProjectBao->getSearchedProject();
            if($Result->getIsSuccess()){
                $ProjectList=$Result->getResultObject();

                foreach ($ProjectList as $project) {
                    ?>
                    <tr>
                        <td><a href="project_member.php?id=<?php echo $project->getProjectId();?>"><img src="<?php echo $project->getProjectThumbnail();?>" alt="Icon" height="100" width="100" class="table-img"><?php
                                echo ' '.$project->getProjectTitle(); ?></a></td>

                        <td><?php if(strlen($project->getProjectDescription())>50){
                                echo substr($project->getProjectDescription(),0,50).'...';
                            }else{
                                echo $project->getProjectDescription();
                            }  ?></td>

                        <td class="table-cell"><?php echo $project->getProjectLanguage();?></td>

                        <td class="table-cell"><?php echo $Result=$_ProjectBao->getYear($project->getProjectYearId())->getResultObject()->getName();?></td>

                        <td class="table-cell"><?php echo $Result=$_ProjectBao->getTerm($project->getProjectTermId())->getResultObject()->getName();?></td>

                        <td><?php echo $Result=$_ProjectBao->getCourse($project->getProjectCourseId())->getResultObject()->getTitle();?></td>

                        <td><?php echo $Result=$_ProjectBao->getDiscipline($project->getProjectDisciplineId())->getResultObject()->getName();?></td>

                        <td class="table-cell"><?php $Result=$_ProjectBao->getTeacher($project->getProjectTeacherId())->getResultObject();
                            echo $Result->getFirstName().' '.$Result->getLastName();?></td>

                        <td class="table-cell"><?php echo $project->getProjectCreatedAt();?></td>

                        <td class="table-cell"><?php echo $project->getProjectUpdatedAt();?></td>

                    </tr>
                    <?php
                }
            }
            ?>
        </table>
    </div>
    </div>
    <?php
}
?>

<!--Script for loading searching options-->
<script>
    //Load on postback
    $(document).ready(function() {
        cbFunction();
    });

    function cbFunction() {
        //Title CB
        if($('#cbtitle').prop('checked')){
            $('#divtitle').show();
            $('#title').prop('required',true);
        }else {
            $('#divtitle').hide();
            $('#title').prop('required',false);
            $('#title').val(null);
        }

        //Language CB
        if($('#cblanguage').prop('checked')){
            $('#divlanguage').show();
            $('#language').prop('required',true);
        }else{
            $('#divlanguage').hide();
            $('#language').prop('required',false);
            $('#language').val(null);

        }

        //Year CB
        if($('#cbyear').prop('checked')){
            $('#divyear').show();
            $('#year_id').prop('required',true);
        }else{
            $('#divyear').hide();
            $('#year_id').prop('required',false);
            $('#year_id').val(null);
        }

        //Term CB
        if($('#cbterm').prop('checked')){
            $('#divterm').show();
            $('#term_id').prop('required',true);
        }else{
            $('#divterm').hide();
            $('#term_id').prop('required',false);
            $('#term_id').val(null);
        }

        //Course CB
        if($('#cbcourse').prop('checked')){
            $('#divcourse').show();
            $('#course_id').prop('required',true);
        }else{
            $('#divcourse').hide();
            $('#course_id').prop('required',false);
            $('#course_id').val(null);
        }

        //Discipline CB
        if($('#cbdiscipline').prop('checked')){
            $('#divdiscipline').show();
            $('#discipline_id').prop('required',true);
        }else{
            $('#divdiscipline').hide();
            $('#discipline_id').prop('required',false);
            $('#discipline_id').val(null);
        }

        //Teacher CB
        if($('#cbteacher').prop('checked')){
            $('#divteacher').show();
            $('#teacher_id').prop('required',true);
        }else{
            $('#divteacher').hide();
            $('#teacher_id').prop('required',false);
            $('#teacher_id').val(null);
        }

        //Member CB
        if($('#cbmember').prop('checked')){
            $('#divmember').show();
            $('#member_id').prop('required',true);
        }else{
            $('#divmember').hide();
            $('#member_id').prop('required',false);
            $('#member_id').val(null);
        }

        //Date CB
        if($('#cbdate').prop('checked')){
            $('#divcreated_at').show();
            $('#created_at').prop('required',true);
        }else{
            $('#divcreated_at').hide();
            $('#created_at').prop('required',false);
            $('#created_at').val(null);
        }
    }
</script>