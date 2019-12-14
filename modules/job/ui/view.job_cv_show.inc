<?php

include_once 'blade/view.job_cv_show.blade.inc';
include_once COMMON.'class.common.inc';

?>

<div class="panel-default">
    <div class="panel-body">
    	<?php
    		if(isset($_SESSION['cvid'])){
    			$Result = $_JobCVShowBAO->getCV($_SESSION['cvid']);
    			unset($_SESSION['cvid']);
    		}
    		else{
	    		$globalUser = '';
				$globalUser = $_SESSION["globalUser"];
				$Result = $_JobCVShowBAO->getCV($globalUser->getID());
			}
			//if DAO access is successful to load all the Jobs then show them one by one
			if($Result->getIsSuccess()){
				$CV = $Result->getResultObject();
		?>
    	<div id="full_cv">
			<div id="jms_cv_header">
				<div id="jms_name_appearence">
					<h1><?php echo $CV->getName(); ?></h1>
					<h2><?php echo $CV->getsector(); ?></h2>
				</div>
				<div id="jms_cv_link">
					<a id="jms_cv_link_email" href="mailto:name@yourdomain.com"><?php echo $CV->getemail(); ?></a>
					<p id="jms_cv_link_phone"><?php echo $CV->getphone(); ?></p>
				</div>
			</div>
			<div class="jms_cv_body">
				<div class="jms_cv_body_ratio">
					<div class="jms_cv_body_profile_head">
						<h2>Profile</h2>
					</div>
					<div class="jms_cv_body_profile_details">
						<p>
							<?php echo $CV->getprofile(); ?>
						</p>
					</div>
				</div>

				<div class="jms_cv_body_ratio">
					<div class="jms_cv_body_skills_header">
						<h2>Skills</h2>
					</div>
					<div class="jms_cv_body_skills_details">
						<?php
							for($i = 0; $i < sizeof($CV->getskills()); $i++) {
								?>
							<div class="talent">
								<h2><?php echo $CV->getskills()[$i]->getname(); ?></h2>
								<p><?php echo $CV->getskills()[$i]->getdetails(); ?></p>
							</div>
							<?php
							}
						?>
					</div>
				</div>

				<div class="jms_cv_body_ratio width">
					<div class="jms_cv_body_technical_header">
						<h2>Technical</h2>
					</div>
					<div class="jms_cv_body_technical_details">
						<p><?php echo $CV->gettechnical_skill(); ?></p>
					</div>
				</div>

				<div class="jms_cv_body_ratio">
					<div class="jms_cv_body_experience_header">
						<h2>Experience</h2>
					</div>
					<div class="jms_cv_body_experience_details">
							<?php
							for($i = 0; $i < sizeof($CV->getexperience()); $i++) {
								?>
								<div class="job">
									<h2><?php echo $CV->getexperience()[$i]->getjobname(); ?></h2>
									<h3><?php echo $CV->getexperience()[$i]->getjobposition(); ?></h3>
									<h4><?php echo $CV->getexperience()[$i]->getworkingyear(); ?></h4>
									<p><?php echo $CV->getexperience()[$i]->getworkdetails(); ?> </p>
								</div>
							<?php
							}
							?>
					</div>
				</div>
				<div class="jms_cv_body_ratio width">
					<div class="jms_cv_body_education_header">
						<h2>Education</h2>
					</div>
					<?php
					for($i = 0; $i < sizeof($CV->geteducation()); $i++) {
						?>
						<div class="jms_cv_body_education_details">
							<h2><?php echo $CV->geteducation()[$i]->getinstituition(); ?></h2>
							<h3><?php echo $CV->geteducation()[$i]->getsubject(); ?> &mdash; <strong><?php echo $CV->geteducation()[$i]->getcgpa(); ?> GPA</strong> </h3>
						</div>
					<?php
					}
					?>
				</div>
			</div>
			<div id="jms_cv_footer">
				<p><?php echo $CV->getName(); ?> &mdash; <a href="mailto:name@yourdomain.com"><?php echo $CV->getemail(); ?></a> &mdash; <?php echo $CV->getphone(); ?></p>
			</div><!--// footer -->
	    </div>
	    <?php
			}
			else{
				echo $Result->getResultObject(); //giving failure message
			}
		?>
    </div>
</div>