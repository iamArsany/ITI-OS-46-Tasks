<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Registration Page</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css" rel="stylesheet">
    <style>
        .error-text { color: #dc3545; font-size: 0.85rem; display: none; margin-top: 4px; }
        .form-label { font-weight: 500; }
        .card { border-radius: 15px; }
    </style>
</head>
<body class="bg-light">

    <div class="container mt-5 mb-5">
        <div class="card p-4 shadow-sm" style="max-width: 650px; margin: auto;">
            <h2 class="mb-4 text-center border-bottom pb-2">User Registration</h2>
            
            <form id="regForm" action="done.php" method="POST" enctype="multipart/form-data" onsubmit="return validateForm()">
                
                <div class="row mb-3">
                    <div class="col-md-6">
                        <label class="form-label">First Name</label>
                        <input type="text" name="fname" id="fname" class="form-control">
                        <div id="fnameError" class="error-text">Required. Letters only (no numbers).</div>
                    </div>
                    <div class="col-md-6">
                        <label class="form-label">Last Name</label>
                        <input type="text" name="lname" id="lname" class="form-control">
                        <div id="lnameError" class="error-text">Required. Letters only (no numbers).</div>
                    </div>
                </div>

                <div class="mb-3">
                    <label class="form-label">Address</label>
                    <textarea name="address" id="address" class="form-control" rows="3"></textarea>
                    <div id="addressError" class="error-text">Address is required.</div>
                </div>

                <div class="mb-3">
                    <label class="form-label">Country</label>
                    <select name="country" id="country" class="form-select">
                        <option value="Egypt">Egypt</option>
                        <option value="USA">USA</option>
                        <option value="UK">UK</option>
                    </select>
                    <div id="countryError" class="error-text">Please select a country.</div>
                </div>

                <div class="mb-3">
                    <label class="form-label d-block">Gender</label>
                    <div class="form-check form-check-inline">
                        <input class="form-check-input" type="radio" name="gender" value="Male" id="male">
                        <label class="form-check-label" for="male">Male</label>
                    </div>
                    <div class="form-check form-check-inline">
                        <input class="form-check-input" type="radio" name="gender" value="Female" id="female">
                        <label class="form-check-label" for="female">Female</label>
                    </div>
                    <div id="genderError" class="error-text">Gender selection is required.</div>
                </div>

                <div class="mb-3">
                    <label class="form-label d-block">Skills</label>
                    <div class="row">
                        <div class="col-6">
                            <div class="form-check">
                                <input class="form-check-input skill-check" type="checkbox" name="skills[]" value="PHP" id="skill1">
                                <label class="form-check-label" for="skill1">PHP</label>
                            </div>
                            <div class="form-check">
                                <input class="form-check-input skill-check" type="checkbox" name="skills[]" value="J2SE" id="skill2">
                                <label class="form-check-label" for="skill2">J2SE</label>
                            </div>
                        </div>
                        <div class="col-6">
                            <div class="form-check">
                                <input class="form-check-input skill-check" type="checkbox" name="skills[]" value="MySQL" id="skill3">
                                <label class="form-check-label" for="skill3">MySQL</label>
                            </div>
                            <div class="form-check">
                                <input class="form-check-input skill-check" type="checkbox" name="skills[]" value="PostgreSQL" id="skill4">
                                <label class="form-check-label" for="skill4">PostgreSQL</label>
                            </div>
                        </div>
                    </div>
                    <div id="skillsError" class="error-text">Select at least one skill.</div>
                </div>

                <div class="mb-3">
                    <label class="form-label">Username</label>
                    <input type="text" name="username" id="username" class="form-control">
                    <div id="userError" class="error-text">Username is required.</div>
                </div>

                <div class="mb-3">
                    <label class="form-label">Password</label>
                    <input type="password" name="password" id="password" class="form-control" placeholder="8 chars, lowercase, no special">
                    <div id="passError" class="error-text">Password must be exactly 8 characters (lowercase/numbers/underscores only).</div>
                </div>

                <div class="mb-3">
                  <label class="form-label">Profile Image (Max 2MB, JPG/PNG only)</label>
                  <input type="file" name="profile_image" id="profile_image" class="form-control" accept=".jpg,.jpeg,.png">
                 <div id="imageError" class="error-text">Please upload a valid JPG or PNG (Max 2MB).</div>
               </div>

                <div class="mb-3">
                    <label class="form-label">Department</label>
                    <input type="text" name="dept" value="OpenSource" class="form-control bg-light" readonly>
                </div>

                <div class="alert alert-secondary py-2 mb-4">
                    <strong>Sh68Sa</strong><br>
                    <label class="small mb-1">Enter the code above:</label>
                    <input type="text" name="captcha_input" id="captcha_input" class="form-control">
                    <input type="hidden" name="captcha_real" value="Sh68Sa">
                    <div id="captchaError" class="error-text">Captcha is required.</div>
                </div>

                <div class="d-flex gap-2">
                    <button type="submit" class="btn btn-primary px-4">Submit Registration</button>
                    <button type="reset" class="btn btn-outline-secondary px-4">Reset</button>
                </div>

            </form>
        </div>
    </div>

    <script>
    function validateForm() {
        let isValid = true;
        
        // Hide all previous errors
        document.querySelectorAll('.error-text').forEach(el => el.style.display = 'none');

        // Name Validation
        const nameRegex = /^[a-zA-Z\s]+$/;
        const fname = document.getElementById('fname').value;
        const lname = document.getElementById('lname').value;
        if (!fname || !nameRegex.test(fname)) {
            document.getElementById('fnameError').style.display = 'block';
            isValid = false;
        }
        if (!lname || !nameRegex.test(lname)) {
            document.getElementById('lnameError').style.display = 'block';
            isValid = false;
        }

        // Basic Text Fields
        if (!document.getElementById('address').value.trim()) { document.getElementById('addressError').style.display = 'block'; isValid = false; }
        if (!document.getElementById('country').value) { document.getElementById('countryError').style.display = 'block'; isValid = false; }
        if (!document.getElementById('username').value.trim()) { document.getElementById('userError').style.display = 'block'; isValid = false; }

        // Gender
        if (!document.querySelector('input[name="gender"]:checked')) {
            document.getElementById('genderError').style.display = 'block';
            isValid = false;
        }

        // Skills
        const skillsChecked = document.querySelectorAll('.skill-check:checked');
        if (skillsChecked.length === 0) {
            document.getElementById('skillsError').style.display = 'block';
            isValid = false;
        }

        // Password: Exactly 8, lowercase/num/_
        const pass = document.getElementById('password').value;
        const passRegex = /^[a-z0-9_]{8}$/;
        if (!passRegex.test(pass)) {
            document.getElementById('passError').style.display = 'block';
            isValid = false;
        }

        // Image Validation
        const imageInput = document.getElementById('profile_image');
        if (imageInput.files.length === 0) {
            document.getElementById('imageError').style.display = 'block';
            isValid = false;
        }


        // Captcha
        if (!document.getElementById('captcha_input').value.trim()) {
            document.getElementById('captchaError').style.display = 'block';
            isValid = false;
        }

        return isValid;
    }
    </script>

</body>
</html>
