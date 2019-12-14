<?php
include_once 'blade/view.job_cv_create.blade.inc';
include_once 'blade/view.job_cv_show.blade.inc';
include_once COMMON.'class.common.inc';

?>

<div class="panel panel-default">
    <div class="panel-heading">
    	Update CV
    </div>
    <div class="panel-body">
    	<?php
    		$globalUser = '';
			$globalUser = $_SESSION["globalUser"];
			$Result = $_JobCVShowBAO->getCV($globalUser->getID());
			//if DAO access is successful to load all the Jobs then show them one by one
			if($Result->getIsSuccess()){
				$CV = $Result->getResultObject();
		?>
    	<div id="form">
			<form method="post" class="form-horizontal">

				<input type="hidden" name="txtCVID" class="form-control" value="<?php echo $CV->getID(); ?>"/>

				<div class="form-group">
	              	<label class="control-label col-sm-4" for="txtCVSector">Your Proficient Sector**:</label>
	              	<div class="col-sm-6">
	              		<input type="text" name="txtCVSector" class="form-control" placeholder="Give a good title of your efficiency" value="<?php echo $CV->getsector(); ?>" required/>
				  	</div>
				</div>
		
				<div class="form-group">
	              	<label class="control-label col-sm-4" for="txtCVEmail">Your CV Email**:</label>
	              	<div class="col-sm-6">  		
						<input type="text" name="txtCVEmail" class="form-control" placeholder="Give your email no" value="<?php echo $CV->getemail(); ?>" required/>
					</div>
				</div>

				<div class="form-group">
	              	<label class="control-label col-sm-4" for="txtCVPhone">Your CV Phone**:</label>
	              	<div class="col-sm-6">  		
						<input type="text" name="txtCVPhone" class="form-control" placeholder="Your Phone Number" value="<?php echo $CV->getphone(); ?>" required/>
					</div>
				</div> 

				<div class="form-group">
	              	<label class="control-label col-sm-4" for="txtCVProfile">Short Profile description(Max-500words)**:</label>
	              	<div class="col-sm-6">	
						<textarea name="txtCVProfile" class="form-control" rows="4" cols="50" maxlength="500" placeholder="Profile description" required><?php echo $CV->getprofile(); ?></textarea>
					</div>
				</div>

					<div class="form-group">
		              	<label class="control-label col-sm-4" for="txtCVSkillheadOne">Skill Set:</label>
		              	<div class="col-sm-6">
		              		<input type="hidden" id="skillnumber" name="skillnumber" class="form-control" value="<?php echo sizeof($CV->getskills()); ?>"/>
		              		<?php
							for($i = 0; $i < sizeof($CV->getskills()); $i++) {
								?>
			              		<input type="text" name="<?php echo 'txtCVSkillHead_'.$i; ?>" class="form-control" placeholder="Skill header 1" value="<?php echo $CV->getskills()[$i]->getname(); ?>"/>	
								<textarea name="<?php echo 'txtCVSkillDetails_'.$i; ?>" class="form-control" rows="4" cols="50" maxlength="500" placeholder="Skill description 1" ><?php echo $CV->getskills()[$i]->getdetails(); ?></textarea>

								<br>
							<?php
								}
							?>
							<div id="skillset"></div>

							<div class="form-group">        
				              	<div class="col-sm-offset-2 col-sm-10">
									<input type="button" value="Add more" onclick="addskill()"/>
							    </div>
				            </div>
						</div>
					</div>

				<div class="form-group">
	              	<label class="control-label col-sm-4" for="txtCVTechnicalSkills">Technical Skill Set**(Max-500words)**:</label>
	              	<div class="col-sm-6">	
						<textarea name="txtCVTechnicalSkills" class="form-control" rows="4" cols="50" maxlength="500" placeholder="Such as.. XHTML,CSS,Javascript,Jquery" required><?php echo $CV->gettechnical_skill(); ?></textarea>
					</div>
				</div>
				<div class="form-group">
	              	<label class="control-label col-sm-4" for="txtCVExperienceNameOne">Experience:</label>
	              	<div class="col-sm-6">
	              		<input type="hidden" name="experiencenumber" id="experiencenumber" class="form-control" value="<?php echo sizeof($CV->getexperience()); ?>"/>
	              		<?php
						for($i = 0; $i < sizeof($CV->getexperience()); $i++) {
							?>
		              		<input type="text" name="<?php echo 'txtCVExperienceName_'.$i; ?>" class="form-control" placeholder="Experience Proffession Name" value="<?php echo $CV->getexperience()[$i]->getjobname(); ?>"/>	
		              		<input type="text" name="<?php echo 'txtCVExperiencePost_'.$i; ?>" class="form-control" placeholder="Experience Proffession Post" value="<?php echo $CV->getexperience()[$i]->getjobposition(); ?>"/>	
		              		<input type="text" name="<?php echo 'txtCVExperienceTimeSpan_'.$i; ?>" class="form-control" placeholder="Experience Proffession Time Span such as = 2007-2009" value="<?php echo $CV->getexperience()[$i]->getworkingyear(); ?>"/>	
							<textarea name="<?php echo 'txtCVExperienceDetails_'.$i; ?>" class="form-control" rows="4" cols="50" maxlength="500" placeholder="Experience Proffession description"><?php echo $CV->getexperience()[$i]->getworkdetails(); ?></textarea>

							<br>
						<?php
							}
						?>
						<div id="experienceset"></div>

						<div class="form-group">        
			              	<div class="col-sm-offset-2 col-sm-10">
								<input type="button" value="Add more" onclick="addexperience()"/>
						    </div>
			            </div>
					</div>
				</div>
				<div class="form-group">
	              	<label class="control-label col-sm-4" for="txtCVEducationInstituition_0">Education**:</label>
	              	<div class="col-sm-6">
	              		<input type="hidden" name="educationnumber" id="educationnumber" class="form-control" value="<?php echo sizeof($CV->geteducation()); ?>"/>
	              		<?php
						for($i = 0; $i < sizeof($CV->geteducation()); $i++) {
							?>
		              		<input type="text" name="<?php echo 'txtCVEducationInstituition_'.$i; ?>" class="form-control" placeholder="Experience Education Instituition" value="<?php echo $CV->geteducation()[$i]->getinstituition(); ?>"/>	
		              		<input type="text" name="<?php echo 'txtCVEducationSubject_'.$i; ?>" class="form-control" placeholder="Experience Education Subject" value="<?php echo $CV->geteducation()[$i]->getsubject(); ?>"/>	
		              		<input type="text" name="<?php echo 'txtCVEducationGPA_'.$i; ?>" class="form-control" placeholder="Experience Education GPA such as = 4.0" value="<?php echo $CV->geteducation()[$i]->getcgpa(); ?>"/>	
							<br>
						<?php
							}
						?>
						<div id="educationset"></div>

						<div class="form-group">        
			              	<div class="col-sm-offset-2 col-sm-10">
								<input type="button" value="Add more" onclick="addeducation()"/>
						    </div>
			            </div> 
					</div>
				</div>
		        <div class="form-group">        
	              	<div class="col-sm-offset-2 col-sm-10">
						<button type="submit" value="update" name="update">Update</button>
				    </div>
	            </div> 
			</form>
		</div>
		<?php
			}
			else{
				echo $Result->getResultObject(); //giving failure message
			}
		?>
		<div id="toastME">
			Some Text Message..
		</div>
    </div>
</div>