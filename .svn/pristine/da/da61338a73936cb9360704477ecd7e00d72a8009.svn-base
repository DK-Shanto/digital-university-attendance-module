<?php
include_once 'blade/view.job_application.blade.inc';
include_once COMMON.'class.common.inc';
?>

<div class="panel panel-default">
    <div class="panel-heading">
    	Job Application Informations
    </div>

<div class="panel-body over">
    	<table class="table table-bordered">
	    	<?php
	    		$globalUser = '';
				$globalUser = $_SESSION["globalUser"];
				$Result = $_JobApplicationBAO->getMyApplication($globalUser->getID());
				//if DAO access is successful to load all the users then show them one by one
				if($Result->getIsSuccess()){
					$ApplicationList = $Result->getResultObject();
					?>
					<tr>
						<th>Job Title</th>
						<th>Application Date</th>
					</tr>
					<?php
					for($i = 0; $i < sizeof($ApplicationList); $i++) {
						$Application = $ApplicationList[$i];
						?>
					    <tr>
						    <td><?php echo $Application->getjobname(); ?></td>
						    <td><?php echo $Application->getSubmissionDate(); ?></td>
						    <td>
						    <a href="?details=<?php echo $Application->getJobID(); ?>" onclick="return confirm('sure to See !'); " >See This Job details</a>
						    </td>
					    </tr>
					<?php
					}
				}
				else{
					echo $Result->getResultObject(); 
				}
			?>
		</table>
    </div>
    <?php
    	if(isset($_GET['details'])){
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
					</div>
				<?php
		}
		?>
</div>