<?php

include_once 'blade/view.job_list.blade.inc';
include_once COMMON.'class.common.inc';

?>

<div class="panel panel-default">
    <div class="panel-heading">
    	New Job Information
    </div>
    <div class="panel-body">
    	<?php
			$Result = $_JobListBAO->getAllJobs();
			//if DAO access is successful to load all the Jobs then show them one by one
			if($Result->getIsSuccess()){
				$JobList = $Result->getResultObject();
				?>
				<?php
				for($i = 0; $i < sizeof($JobList); $i++) {
					$Job = $JobList[$i];
					?>
					<div class="jms_block">
					    <p class="jms_title inline"><?php echo $Job->getTitle(); ?></p>

					    <p class="jms_Subtitle inline">( <?php echo $Job->getSubtitle(); ?> )</p><br>

					    <p class="jms_PublishDate inline"><span>Publish Date : </span><?php echo $Job->getPublishDate(); ?></p>

					    <p class="jms_Organization inline"><span>Organization : </span><?php echo $Job->getOrganization(); ?></p>

					    <p class="jms_EmploymentType inline"><span>Employment Type : </span><?php echo $Job->getEmploymentType()?></p><br>

					    <p class="jms_Qualification inline"><span> Education Qualification : </span><?php echo $Job->getQualification()?></p>

					    <p class="jms_Gender inline"><span>Gender : </span><?php echo $Job->getGender(); ?></p>

					    <p class="jms_AgeLimit inline"><span>Age Limit : </span><?php echo $Job->getAgeLimit(); ?></p>

					    <p class="jms_NumberOfVacancy inline"><span>Vacancy : </span><?php echo $Job->getNumberOfVacancy(); ?></p><br>

					    <p class="jms_Email inline"><span>Contact Email : </span><?php echo $Job->getEmail(); ?></p>

					    <p class="jms_ContactNumber inline"><span>Contact Phone : </span><?php echo $Job->getContactNumber()?></p>

					    <p class="jms_Salary inline"><span>Salary : </span><?php echo $Job->getSalary(); ?></p><br>

					    <p class="jms_JobExperience inline"><span>Job Experience : </span><?php echo $Job->getJobExperience()?></p>

					    <p class="jms_Location inline"><span> Job Location : </span><?php echo $Job->getLocation(); ?></p><br>

					    <p class="jms_LastDateOfApplication inline"><span>Last Application Date : </span><?php echo $Job->getLastDateOfApplication(); ?></p>
					    <?php
					    	if($Job->getLastDateOfApplication()<date("Y-m-d")){
					    ?>
					    	<p class="jms_submit inline" style="color: yellow;" >Apply date ended</p>
					    <?php
						}
						else{
						?>
					    	<a class="jms_submit inline" href="?apply=<?php echo $Job->getID(); ?>">Apply</a>
					     <?php
						}
						?>
					</div>
				<?php
				}
			}
			else{
				echo $Result->getResultObject(); //giving failure message
			}
		?>
    </div>
</div>